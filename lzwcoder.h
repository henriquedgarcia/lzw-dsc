#ifndef LZWCODER_H
#define LZWCODER_H

#include <string>

using namespace std;

class LZWCoder
{
public:
  LZWCoder();
  int Encoder(string nameIn, string nameOut);
};

#endif // LZWCODER_H
