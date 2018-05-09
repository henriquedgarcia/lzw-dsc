#include "lzwcodec.h"

using namespace std;

LZWCodec::LZWCodec()
{
  for(size_t i=0; i< m_alphabetSize; i++)
    m_dictionary.push_back (deque<uc> {(uc) i});

  //  cout << "inicializando dicionário\n";
  //  for(deque<uc> *i : m_dictionary)
  //    for (uc j : *i) cout << "caractere = " << (int) j << endl;
}

int LZWCodec::Encoder(string nameIn, string nameOut)
{
  OpenFiles(nameIn, nameOut);

  //  struct doublet output;

  //  while(output.eof != true)
  //    {
  //      output = FindPhrase();
  //      m_output.push_back (output.index);
  //      m_dictionary.push_back (output.string);
  //    }
  deque<uc> phrase;
  size_t index;
  int c;

  while((c = m_inputFile.get()) != EOF)
    {

      for(size_t i = 0; i <= m_dictionary.size (); i++)
        {

        }

//      //inicia a frase com 1 caractere
//      phrase = deque<uc>{(uc) c};
//      cout << "Nova frase com caractere c = " << (char) c << endl;

//      // Procura esse caractere no dicionário -- corretude -> Esse loop funciona Enquanto m_dictionary > 0. Se for igual se torna um loop infinito porque o unget() lá em baixo devolve o get lá de cima. Aí fica get -> unget -> get -> ...
//      cout << "Procurando frase = \""; for (auto i : phrase) cout << (char) i; cout << "\"\n";
//      for(size_t i = 256; i <= m_dictionary.size (); i++)
//        {
//          // Se encontrar esse caractere
//          if (m_dictionary[i] == phrase)
//            {
//              cout << "Encontrado na posição i = " << (int) i << endl;
//              // Salve a posição dessa correspondência
//              index = i;

//              // procura se é o proximo caractere é um EOF
//               if (m_inputFile.peek() == EOF) {break;}

//              // Coloque mais um caractere na frase e procure-o no dicionário
//              phrase.push_back ((uc) m_inputFile.get());
//              cout << "Procurando frase = \""; for (auto i : phrase) cout << (char) i; cout << "\"\n";
//            }
//        }
//      cout << " Não encontrado! Colocando frase = ";
//      for (auto i : phrase) cout << (char) i;
//      cout << " no íncice = " << (int) m_dictionary.size ()<< endl;


//      // Quando terminar o dicionário teremos o indice da ultima correspondência e a menor frase frase sem correspondencia no dicionário
//      // salvar índice na saída
//      m_output.push_back (index);

//      if (m_inputFile.peek() == EOF) {break;}

//      // Atualiza dicionário com a nova frase
//      m_dictionary.push_back (phrase);

//      // devolve o ultimo caractere que será o primeiro da proxima iteração
//      m_inputFile.unget ();
    }

  if (m_output.size () == 0)
    {
      cout << "Erro ao codificar. EOF muito cedo. Saída de tamanho 0.\n";
      exit(-1);
    }

  cout << "\nMostrando m_output." << endl;
  for (auto i : m_output) cout << (int) i << "-"; cout << endl;
  cout << "Mostrando m_dictionary." << endl;
  for (auto i : m_dictionary)
    {for (auto j : i) cout << (char) j; cout << endl;}

  return 0;
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


