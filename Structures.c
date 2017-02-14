#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float *data;
  unsigned int N;
  unsigned int M;
}MATRIX;

MATRIX * allocateMatrix(unsigned char *N, unsigned char *M);
void deallocateMatrix(MATRIX* ptr);
void insertData(MATRIX* ptr);
void printMatrix(MATRIX* ptr);
void transposeMatrix(MATRIX* ptr1, MATRIX* ptr2);

int main(int argc, char const *argv[]) {
  MATRIX *pM, *pMT;
  unsigned char N, M;

  printf("Ingrese las dimensiones de la matriz\n\tN: ");
  scanf("%hhu", &N);
  printf("\tM: ");
  scanf("%hhu", &M);

  pM = allocateMatrix(&N, &M);
  pMT = allocateMatrix(&M, &N);
  insertData(pM);
  printf("\n");
  printMatrix(pM);
  printf("\nLa matriz transpuesta es:\n");
  transposeMatrix(pM, pMT);
  printMatrix(pMT);
  deallocateMatrix(pM);
  deallocateMatrix(pMT);
  return 0;
}

MATRIX * allocateMatrix(unsigned char *N, unsigned char *M){
  MATRIX *ptr;
  ptr = (MATRIX *)malloc(sizeof(MATRIX));
  ptr->data = (float *)malloc((*N)*(*M)*sizeof(float));
  ptr->N = *N;
  ptr->M = *M;
  return ptr;
}

void deallocateMatrix(MATRIX* pM) {
  free(pM->data);
  free(pM);
}

void insertData(MATRIX *ptr) {
  unsigned char i, j;
  for (i = 0; i < ptr->N; i++)
  for (j = 0; j < ptr->M; j++) {
    printf("\tdata[%hhu][%hhu] = ", i+1, j+1);
    scanf("%f", ptr->data+i*(ptr->M)+j);
  }
}

void printMatrix(MATRIX* ptr) {
  unsigned char i, j;
  for (i = 0; i < ptr->N; i++) {
    for (j = 0; j < ptr->M; j++)
      printf("\tdata[%hhu][%hhu] = %g", i+1, j+1, ptr->data[i*ptr->M+j]);
    printf("\n");
  }
}

void transposeMatrix(MATRIX* ptr1, MATRIX* ptr2) {
  unsigned char i, j;
  for (i = 0; i < ptr1->N; i++)
  for (j = 0; j < ptr1->M; j++)
    ptr2->data[j*ptr1->N+i] = ptr1->data[i*ptr1->M+j];
}
