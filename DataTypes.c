#include <stdio.h>
int main(int argc, char const *argv[]) {
  // Definición de todos los tipos de datos
  int integer;
  char character;
  float reals;
  double reald;
  short int short_int;
  long int long_int;
  long double long_real;
  // Imprimir en pantalla todos los tamaños, sizeof()
  printf("El tamaño en bytes del entero es: %lu\n", sizeof(integer));
  printf("El tamaño en bytes del caracter es: %lu\n", sizeof(character));
  printf("El tamaño en bytes del float es: %lu\n", sizeof(reals));
  printf("El tamaño en bytes del double es: %lu\n", sizeof(reald));
  printf("El tamaño en bytes del short int es: %lu\n", sizeof(short_int));
  printf("El tamaño en bytes del long int es: %lu\n", sizeof(long_int));
  printf("El tamaño en bytes del long double es: %lu\n", sizeof(long_real));
  return 0;
}
