// File lain yang digunakan
#include <stdio.h>
#include <string.h>


int main() {
  // KAMUS
  char str[10];
  int i, j;

  // ALGORTIMA
  printf("Masukkan string : ");
  scanf("%s", str);
  printf("String = %s\n", str);

  i = strlen(str);
  printf("Panjang string = %d\n", i);

  i = 0;
  for (j = 2; j < strlen(str); j++)
  {
    str[i] = str[j];
    i++;
  }
  str[i] = '\0';
  printf("String baru = %s\n", str);
  printf("Panjang baru = %d\n", strlen(str));

  return 0;
}
