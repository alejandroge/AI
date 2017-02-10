#include <stdio.h>
int main(int argc, char const *argv[]) {
  int ent;
  char car;
  float reals;
  double reald;
  short int ent_corto;
  long int ent_largo;
  long double real_largo;
  printf("El tamaño en bytes del entero es: %lu\n", sizeof(ent));
  printf("El tamaño en bytes del caracter es: %lu\n", sizeof(car));
  printf("El tamaño en bytes del float es: %lu\n", sizeof(reals));
  printf("El tamaño en bytes del double es: %lu\n", sizeof(reald));
  printf("El tamaño en bytes del e_corto es: %lu\n", sizeof(ent_corto));
  printf("El tamaño en bytes del e_largo es: %lu\n", sizeof(ent_largo));
  printf("El tamaño en bytes del d_largo es: %lu\n", sizeof(real_largo));
  return 0;
}
