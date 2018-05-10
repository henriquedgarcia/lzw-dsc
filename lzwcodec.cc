#include "lzwcodec.h"

using namespace std;

LZWCodec::LZWCodec()
{
  m_dictionary = deque<deque<uc>>{};

  for(ui i=0; i< m_alphabetSize; i++)
    m_dictionary.push_back (deque<uc> {(uc) i});

  // cout << "inicializando dicionário\n"; for(deque<uc> i : m_dictionary) for (uc j : i) cout << "caractere = " << (int) j << " = " << (char) j << endl;
}

int LZWCodec::Encoder(string nameIn, string nameOut)
{
  OpenFiles(nameIn, nameOut);

  deque<uc> phrase;
  deque<uc> temp;
  ui index = 0;
  int c;

  while((c = m_inputFile.get()) != EOF)
    {
      temp = phrase;
      temp.push_back ((uc) c);
      bool found = false;

      // Se phrase existe no dicionário
      // cout << "\nProcurando temp = "; {for (auto i : temp) cout << (char) i;} cout << endl;
      for (ui i = 0; i < m_dictionary.size (); i++)
        {
          if (m_dictionary[i] == phrase)
            {
              // cout << "phrase = "; for (auto i : phrase) cout << (char) i; cout << ", encontrado no índice = " << i << endl;
              index = i;
            }

          if (m_dictionary[i] == temp)
            {
              // cout << "temp = "; {for (auto i : temp) cout << (char) i;} cout << " encontrada no indice = " << i << ", Atualizando busca" << endl;
              phrase = temp;
              found = true;
              break;
            }
        }

      if (found == false)
        {
          // cout << "temp = "; {for (auto i : temp) cout << (char) i;} cout << " NÃO encontrada. Salvando ultimo indice = " << (ui) index << endl;
          m_dictionary.push_back (temp);
          m_output.push_back (index);
          phrase = deque<uc> {(uc) c};
        }
    }

  for (ui i = 0; i < m_dictionary.size (); i++)
    if (m_dictionary[i] == phrase) {index = i;break;}

  // cout << "Fim dos caracteres gravando index = " << index << "para o phrase = ";for (auto i : phrase) cout << (char) i;cout << endl;

  m_output.push_back (index);

  if (m_output.size () == 1 || m_dictionary.size () < 256)
    {
      cout << "Erro ao codificar. EOF muito cedo. Saída de tamanho 0.\n";
      exit(-1);
    }

  // for debug only
  ShowDic();
  GravaSaida();
  m_outputFile.close ();
  return m_output.size ();
}

int LZWCodec::Decoder(string nameIn, string nameOut)
{
  OpenFiles(nameIn, nameOut);

  deque<uc> phrase;
  uc character;
  ui current;
  ui previous;

  m_inputFile.seekg (0);
  m_inputFile.clear();

  m_inputFile.read((char*) (&current), sizeof(current));
  cout << "current = " << hex <<  current << endl;
  m_outputDecoder = deque<deque<uc>>{m_dictionary[current]};

  previous = current;

  while (m_inputFile.read((char*) (&current), sizeof current))
    {
      if (current < m_dictionary.size())
        {
          m_outputDecoder.push_back (m_dictionary[current]);
          phrase = m_dictionary[previous];
          character = m_dictionary[current].front ();
          phrase.push_back (character);
          m_dictionary.push_back (phrase);
        }
      else
        {
          phrase = m_dictionary[previous];
          character = m_dictionary[previous].front ();
          phrase.push_back (character);
          m_dictionary.push_back (phrase);
          m_outputDecoder.push_back (phrase);
        }

      previous = current;
    }

  GravaSaidaDecoder();
  return m_outputDecoder.size ();
}

void LZWCodec::OpenFiles(string nameIn, string nameOut)
{
  m_inputFile.open (nameIn,ios_base::in|ios_base::binary);
  if(!m_inputFile.is_open())
    cout << "Erro ao abrir entrada" << endl;

  m_outputFile.open (nameOut,ios_base::out|ios_base::binary);
  if(!m_outputFile.is_open())
    cout << "Erro ao abrir saída" << endl;
}

void LZWCodec::GravaSaida(void)
{
  for(ui i : m_output)
    {
      m_outputFile.write((char*) (&i), sizeof i);
    }
}

void LZWCodec::GravaSaidaDecoder(void)
{
  for(deque<uc> phrase : m_outputDecoder)
    {
      for (ui i : phrase)
        m_outputFile.put((char) i);
    }
}

void LZWCodec::ShowDic(void)
{
  cout << "\nMostrando m_dictionary." << endl;
  for (ui i = 256; i < m_dictionary.size (); i++)
    {
      for (auto j : m_dictionary[i])
        cout << (char) j;
      cout << endl;
    }
}

void LZWCodec::ShowOutput(void)
{
  cout << "\nMostrando m_output." << endl;
  for (ui i : m_output)
    {
      cout << dec << i << "-";
    }
  cout << endl;
}




