#include <stdio.h>

void insertData(float *pV, unsigned char *Ne);
void computeMean(float *pV, unsigned char *Ne, float *m);
void printData(float *pV, unsigned char *Ne);

int main(int argc, char const *argv[]) {
  float Vector[100], mean = 0;
  unsigned char Ne;

  printf("¿Cuántos datos ingresará en el arreglo? ");
  scanf("%hhu", &Ne);
  insertData(Vector, &Ne);
  printData(Vector, &Ne);
  computeMean(Vector, &Ne, &mean);
  printf("\n\tLa media de los datos ingresados es: %g\n", mean);

  return 0;
}

void insertData(float *pV, unsigned char *Ne) {
  unsigned char i;
  for (i = 0; i < *Ne; i++) {
    printf("\tdato[%i]= ", i+1);
    scanf("%f", pV+i);
  }
}

void computeMean(float *pV, unsigned char *Ne, float *m) {
  unsigned char i;
  for (i = 0; i < *Ne; i++) {
    *m += pV[i];
  }
  *m /= *Ne;
}

void printData(float *pV, unsigned char *Ne) {
  unsigned char i;
  for (i = 0; i < *Ne; i++)
    printf("\n dato[%i]= %g", i+1, pV[i]);
}
