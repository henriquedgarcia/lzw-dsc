#include <iostream>
#include <lzwcodec.h>
#include <cstring>


using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
   {
     printf("Uso errado: %s arquivo. \n", argv[0]);
     exit(-1);
   }
   int a;
   char saida[100];
   char saida2[100];
   sprintf(saida, "0-%s.lzw", argv[1]);
   sprintf(saida2, "0-%s", argv[1]);

   printf("Salvando como: %s.lzw\n", argv[1]);

  //////////////////////////////////////////////////////////////////////
  cout << "codificando\n";
  LZWCodec Codificador;
  a = Codificador.Encoder(argv[1], saida);
  cout << "codificado = " << a << endl;

  cout << "Decodificando\n";
  LZWCodec Decodificador;
  a = Decodificador.Decoder(saida,saida2);
  cout << "decodificado = " << a << endl;

  return 0;
}
