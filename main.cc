#include <iostream>
#include <lzwcodec.h>
#include <string>

using namespace std;

int main()
{
  string in;
  string out;
  int a;

//   in = "entrada.txt";
//   out = "saida.lzw";

//  LZWCodec codificador;
//  a = codificador.Encoder(in, out);
//  cout << "teste = " << a << endl;

  in = "saida.lzw";
  out = "entradaDecodificada.txt";

  LZWCodec Decodificador;

  a = Decodificador.Decoder(in, out);
  cout << "teste = " << a << endl;

  return 0;
}
