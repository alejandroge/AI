#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float *data;
  unsigned int N;
  unsigned int M;
}MATRIX;

MATRIX * allocateMatrix(unsigned int N, unsigned int M);

int main(int argc, char const *argv[]) {
  MATRIX *pM;

  pM = allocateMatrix();
  return 0;
}

MATRIX * allocateMatrix(unsigned int M, unsigned int N){
  MATRIX *ptr;

}
