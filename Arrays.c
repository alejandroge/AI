#include <stdio.h>

void capturaVector(float *pV, unsigned int *Ne);

int main(int argc, char const *argv[]) {
  float Vector[100];
  unsigned int Ne;

  capturaVector();
  return 0;
}

void capturaVector(float *pV, unsigned int *Ne) {
  unsigned char i, N;
  printf("\n Numero de datos a capturar: ");
  scanf("%u", &N);
  for (i = 0; i < N; i++) {
    printf("\n dato[%i]= ", i+1);
  }
}
