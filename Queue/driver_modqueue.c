/*
Nama File : "driver_modqueue.c"
Driver ADT modqueue (Modified Queue) dengan representasi array secara eksplisit dan alokasi dinamik
Model Implementasi Versi III dengan circular buffer
*/

#include <stdio.h>
#include <stdlib.h>
#include "modqueue.h"
#include "modqueue.c"

Queue Q;
int Max,Life;
customer X;

int main(){
     Life = 3;
     int choice = 1;
     int choicedel;
     while (choice != 2 && choice != 7){
          system("CLS");
          printf("Main Menu\n");
          printf("1. Create an empty Queue\n");
          printf("2. Exit\n");
          printf("\n");

          printf(">> ");
          scanf("%d",&choice);
          printf("\n");
          switch (choice) {
               case 1:
                    printf("Input MaxEl : ");
                    scanf("%d",&Max);
                    CreateEmptyQueue(&Q,Max);

                    while (choice != 7){
                         printf("\n");
                         printf("Functions and Procedures\n");
                         printf("1. IsEmptyQueue\n");
                         printf("2. IsFullQueue\n");
                         printf("3. NBElmtQueue\n");
                         printf("4. AddQueue\n");
                         printf("5. DelQueue\n");
                         printf("6. Move\n");
                         printf("7. Exit\n");
                         printf("Life : %d\n",Life);
                         printf("\n");

                         if (Life <= 0){
                              choice = 7;
                         }
                         else {
                              printf(">> ");
                              scanf("%d",&choice);
                              printf("\n");
                         }
                         switch (choice) {
                              case 1:
                                   printf("Queue kosong?\n");
                                   printf("%d\n\n",IsEmptyQueue(Q));
                                   break;

                              case 2:
                                   printf("Queue penuh?\n");
                                   printf("%d\n\n",IsFullQueue(Q));
                                   break;

                              case 3:
                                   printf("Jumlah elemen\n");
                                   printf("%d\n\n",NBElmtQueue(Q));
                                   break;

                              case 4:
                                   AddQueue(&Q);
                                   printf("Queue :\n");
                                   PrintQueue(Q);
                                   printf("\n");
                                   break;

                              case 5:
                                   printf("1.) DelQueue2\n");
                                   printf("2.) DelQueue4\n");
                                   printf(">> ");
                                   scanf("%d",&choicedel);
                                   printf("\n");
                                   if (choicedel == 1){
                                        DelQueue2(&Q,&X);
                                        printf("(%d,%d)\n",InfoJumlah(X),InfoSabar(X));
                                   }
                                   else if (choicedel == 2){
                                        DelQueue4(&Q,&X);
                                        printf("(%d,%d)\n",InfoJumlah(X),InfoSabar(X));
                                   }
                                   if (InfoSabar(X) != Nil){
                                        printf("Jumlah Orang yang dihapus : %d\n",InfoJumlah(X));
                                        printf("Kesabaran Orang yang dihapus : %d\n",InfoSabar(X));
                                   }
                                   else {
                                        printf("Tidak ada kelompok orang yang dihapus\n");
                                   }
                                   printf("Queue :\n");
                                   PrintQueue(Q);
                                   printf("\n");
                                   break;

                              case 6:
                                   KurangSabarQueue(&Q,&Life);
                                   PrintQueue(Q);
                                   break;

                              case 7:
                                   break;

                              default:
                                   printf("Please input a different choice.\n\n");

                         }
                    }

                    DeAlokasiQueue(&Q);
               case 2:
                    printf("Arigatou Gozaimasu!! ^_^\n");
                    break;
               default:
                    printf("Please input a different choice.\n\n");
          }
     }

     return 0;
}
