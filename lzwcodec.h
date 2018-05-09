#ifndef LZWCODER_H
#define LZWCODER_H

#include <string>
#include <fstream>
#include <deque>
#include <iostream>

typedef unsigned char uc;

using namespace std;

class LZWCodec
{
public:
  LZWCodec();
  int Encoder(string nameIn, string nameOut);

private:
  fstream m_inputFile;
  fstream m_outputFile;
  size_t m_alphabetSize = 256;
  deque<deque<uc>> m_dictionary;
  deque<uc> m_output;
  size_t m_index;



  void OpenFiles(string nameIn, string nameOut);
  struct doublet FindPhrase(void);
};

#endif // LZWCODER_H
