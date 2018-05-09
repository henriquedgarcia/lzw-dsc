#include <iostream>
#include <lzwcodec.h>
#include <string>

using namespace std;

int main()
{
  string in = "entrada.txt", out = "saida.lzw";


  LZWCodec codificador;
  int a = codificador.Encoder(in, out);
  cout << "teste = " << a << endl;
  return 0;
}
