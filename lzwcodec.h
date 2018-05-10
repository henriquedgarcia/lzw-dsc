#ifndef LZWCODER_H
#define LZWCODER_H

#include <string>
#include <fstream>
#include <deque>
#include <iostream>

typedef unsigned char uc;
typedef unsigned int ui;


using namespace std;

class LZWCodec
{
public:
  LZWCodec();
  int Encoder(string nameIn, string nameOut);
  int Decoder(string nameIn, string nameOut);

private:
fstream m_inputFile;
fstream m_outputFile;
ui m_alphabetSize = 256;
deque<deque<uc>> m_dictionary;
deque<ui> m_output;
deque<deque<uc>> m_outputDecoder;

  void GravaSaidaDecoder(void);
  void OpenFiles(string nameIn, string nameOut);
  void GravaSaida(void);
  void ShowDic(void);
  void ShowOutput(void);

};

#endif // LZWCODER_H
