#include <stdio.h>

typedef struct{
  float *data;
  unsigned int N;
  unsigned int M;
}MATRIZ;

MATRIZ * crearMatriz(unsigned int N, unsigned int M);

int main(int argc, char const *argv[]) {
  MATRIZ *pM;

  pM = crearMatriz();
  return 0;
}
