#include "modstackt.c"
#include <stdlib.h>
int main(){
  Stack Hand;
  Stack temp;
  CreateEmptyStack(&Hand);
  infostack x;
  x = (infostack) malloc (20 * sizeof(infostack));
  printf("Push Spaghetti Bolognese ke Stack Hand... \n");
  Push(&Hand, "Spaghetti Bolognese");
  printf("\n");

  printf("Push Keju Prancis ke Stack Hand... \n");
  Push(&Hand, "Keju Prancis");
  printf("\n");

  printf("Copy Stack Hand ke Stack temp...\n");
  CopyStack(Hand, &temp);
  printf("\n");

  printf("Hasil Inverse Stack temp:\n");
  InverseStack(&temp);
  PrintStack(temp);
  printf("\n");

  printf("Push Ice Cream ke Stack temp...\n");
  Push(&temp, "Ice Cream\n");
  printf("\n");

  Pop(&temp, &x);
  printf("Barang yang dipop dari Stack temp = %s\n", x);
  printf("\n");

  Pop(&temp, &x);
  printf("Barang yang dipop dari Stack temp = %s\n", x);
  printf("\n");

  printf("Isi Stack temp: \n");
  PrintStack(temp);
  printf("\n");

  printf("Isi Stack Hand: \n");
  PrintStack(Hand);
}
