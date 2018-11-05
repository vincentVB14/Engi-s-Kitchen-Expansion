/*
Nama File : "driver_modqueue.c"
Driver ADT modqueue (Modified Queue) dengan representasi array secara eksplisit dan alokasi dinamik
Model Implementasi Versi III dengan circular buffer
*/

#include <stdio.h>
#include "modqueue.h"
#include "modqueue.c"

Queue Q;
int Max;
infotype X;

int main(){
     int choice = 1;
     while (choice != 2 && choice != 6){
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

                    while (choice != 6){
                         printf("\n");
                         printf("Functions and Procedures\n");
                         printf("1. IsEmptyQueue\n");
                         printf("2. IsFullQueue\n");
                         printf("3. NBElmtQueue\n");
                         printf("4. AddQueue\n");
                         printf("5. DelQueue\n");
                         printf("6. Exit\n");
                         printf("\n");

                         printf(">> ");
                         scanf("%d",&choice);
                         printf("\n");
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
                                   printf("Input Jumlah Orang : ");
                                   scanf("%d",&InfoJumlah(X));
                                   printf("Input Kesabaran orang : ");
                                   scanf("%d",&InfoSabar(X));
                                   AddQueue(&Q,X);
                                   printf("Queue :\n");
                                   PrintQueue(Q);
                                   printf("\n");
                                   break;

                              case 5:
                                   DelQueue(&Q,&X);
                                   printf("Nilai X yang dihapus : %d\n",X);
                                   printf("Queue :\n");
                                   PrintQueue(Q);
                                   printf("\n");
                                   break;
                              case 6:
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
