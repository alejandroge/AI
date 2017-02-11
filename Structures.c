#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float *data;
  unsigned int N;
  unsigned int M;
}MATRIX;

MATRIX * allocateMatrix(unsigned char *N, unsigned char *M);
void deallocateMatrix(MATRIX* ptr);
void insertData(MATRIX* ptr, unsigned char *N, unsigned char *M);
void printMatrix(MATRIX* ptr, unsigned char *N, unsigned char *M);
void transposeMatrix(MATRIX* ptr1, MATRIX* ptr2, unsigned char *N, unsigned char *M);

int main(int argc, char const *argv[]) {
  MATRIX *pM, *pMT;
  unsigned char N,M;

  printf("Ingrese las dimensiones de la matriz\n\tN: ");
  scanf("%hhu", &N);
  printf("\tM: ");
  scanf("%hhu", &M);

  pM = allocateMatrix(&N, &M);
  pMT = allocateMatrix(&M, &N);
  insertData(pM, &N, &M);
  printMatrix(pM, &N, &M);
  transposeMatrix(pM, pMT, &N, &M);
  printMatrix(pMT, &M, &N);
  deallocateMatrix(pM);
  deallocateMatrix(pMT);
  return 0;
}

MATRIX * allocateMatrix(unsigned char *N, unsigned char *M){
  MATRIX *ptr;
  ptr = (MATRIX *)malloc(sizeof(MATRIX));
  ptr->data = (float *)malloc((*N)*(*M)*sizeof(float));
  return ptr;
}

void deallocateMatrix(MATRIX* pM) {
  free(pM->data);
  free(pM);
}

void insertData(MATRIX *ptr, unsigned char *N, unsigned char *M) {
  unsigned char i, j;
  for (i = 0; i < *N; i++)
  for (j = 0; j < *M; j++) {
    printf("\tdata[%hhu][%hhu] = ", i+1, j+1);
    scanf("%f", ptr->data+i*(*M)+j);
  }
}

void printMatrix(MATRIX* ptr, unsigned char *N, unsigned char *M) {
  unsigned char i, j;
  for (i = 0; i < *N; i++) {
    for (j = 0; j < *M; j++)
      printf("\tdata[%hhu][%hhu] = %g", i+1, j+1, ptr->data[i*(*M)+j]);
    printf("\n");
  }
}

void transposeMatrix(MATRIX* ptr1, MATRIX* ptr2, unsigned char *N, unsigned char *M) {
  unsigned char i, j;
  for (i = 0; i < *N; i++)
  for (j = 0; j < *M; j++)
    ptr2->data[j*(*N)+i] = ptr1->data[i*(*M)+j];
}
