# lzw-dsc
Codificador LZW para a disciplina de codificação digital de sinais, ENE-UnB.
Uso:
lzw-dsc inputFile

o programa codificará o arquivo e o salvará com o nome 0-inputFile.lzw
e decodificara o arquivo e o salvará com o nome 0-inputFile


P   -> Um string com as letras a serem procuradas
c   -> um caractere de entrada
dic -> Um vetor de strings
+   -> operador de concatenação
nput -> sequencia de entrada
output -> sequencia de saída

- Pseudocódigo do Codificador -
INICIAR dic com o alfabeto de entrada.
P = {};
c = getc(entrada);
ENQUANTO (c != EOF)
  {
    SE ((P+c) está em dic)
      {
        P = P+c;
      }
    SENÃO
      {
        output.push_back(P)
        dic.push_back(P+c)
        I = {c};
      }
    c = getc(entrada);    
  } 
output.push_back(P)
      
      
      
Pseudocódigo descompactação String
1. No início o dicionário contém todas as raízes possíveis;
2. cW <= primeira palavra código na sequência codificada (sempre é uma raiz);
3. Coloque a string(cW) na sequência de saída;
4. pW <= cW;
5. cW <= próxima palavra código da sequência codificada;
6. A string(cW) existe no dicionário ?
        a. se sim,
                i. coloque a string(cW) na sequência de saída;
                ii. P <= string(pW);
                iii. C <= primeiro caracter da string(cW);
                iv. adicione a string P+C ao dicionário;
        b. se não,
                i. P <= string(pW);
                ii. C <= primeiro caracter da string(pW);
                iii. coloque a string P+C na sequência de saída e adicione-a ao dicionário;
7. Existem mais palavras código na sequência codificada ?
        a. se sim,
                i. volte ao passo 4;
        b. se não,
                i. FIM.
