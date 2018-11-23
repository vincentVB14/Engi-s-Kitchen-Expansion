#include "interface.h"
#include "game_mechanic.h"

#include "Array/modarray.c"
#include "Graph/modgraph.c"
#include "Matriks/modmatriks.c"
#include "Mesin/modmesinkar.c"
#include "Mesin/modmesinkata.c"
#include "Mesin/modmesintree.c"
#include "Point/modpoint.c"
#include "Queue/modqueue.c"
#include "Stack/modstackt.c"
#include "Tree/modpohon.c"

#include "interface.c"
#include "game_mechanic.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//srand(time(NULL));
//rand() % (max_number + 1 - minimum_number) + minimum_number

void clrscr()
{
    system("@cls||clear");
}



////////////////////////////////////////////////////////////////////////////////////////

int main(){
  clrscr();
  boolean customer_chance;
  boolean validmove;
  int choice;
  int money, life, time;
  char *command;
  char *playername;

  Graph MAP;
  Gaddress current_room;

  POINT player;
  POINT mejap; // Masih belum digunakan untuk menunjukkan meja dekat player

  Queue antrian;

  TabInt Order;

  Stack Hand;
  Stack Tray;

  BinTree resep;

  command = (char *) malloc (6 * sizeof(char)); //Alokasi string command sepanjang 6 karakter
  playername = (char *) malloc (15 * sizeof(char)); //Alokasi nama player sepanjang 15 karakter
  strcpy(playername,""); //Inisialisasi string nama player

  //Create Empties
  CreateEmptyStack(&Hand);
  CreateEmptyStack(&Tray);
  CreateEmptyArray(&Order);
  CreateEmptyQueue(&antrian, 5);
  CreateEmptyGraph(&MAP);
  printf("Reading tree\n");
  CreateTreeMakanan(&resep);
  printf("Tree telah terbaca\n");
  BacaPeta(&MAP, &player);
  printf("Map telah terbaca\n");
  current_room = SearchRuangan(MAP, CurrentRoom(MAP));
  //Nilai awal
  money = 0;
  life = 3;
  time = 0;

  clrscr();
  //MainMenu();
  printf(">>> ");
  //Membaca pilihan dari player
  scanf("%d", &choice);
  switch(choice){
    case 1:{
      NewGame(playername);
      sleep(1.5);
      StartGame(playername);
      break;
    }
    case 2:{
      StartGame(playername);
      break;
    }
    case 3:{
      //LoadGame();
      break;
    }
    case 4:{
      exit(0);
    }
    default:{
      printf("Wrong choice. Exiting program...");
      exit(0);
    }
  }
  sleep(1.5);
  if(choice == 1 || choice == 2 || choice == 3){
    while(life > 0){
      clrscr();
      customer_chance = (rand() % 100) < 5;
      if(customer_chance){
        AddQueue(&antrian);
      }

      Play(playername, money, life, time, current_room, MAP);

      printf(">>> ");
      scanf("%s", command);
      if(strcmp(command, "GU") == 0){
        GoUP(&MAP, &current_room, &player, &validmove);
      } else if(strcmp(command, "GD") == 0){
        GoDOWN(&MAP, &current_room, &player, &validmove);
      } else if(strcmp(command, "GL") == 0){
        GoLEFT(&MAP, &current_room, &player, &validmove);
      } else if(strcmp(command, "GR") == 0){
        GoRIGHT(&MAP, &current_room, &player, &validmove);
      } else if(strcmp(command, "ORDER") == 0){
        mejap = MejaDekatPlayer(Ruangann(current_room), player);
        if((Ordinat(mejap) == 0)&&(Absis(mejap) == 0)) {
          printf("Tidak ada customer dekat player\n");
          sleep(2);
        } else if (!MElmt2(Ruangann(current_room), Ordinat(mejap), Absis(mejap))) {
          printf("Meja tersebut tidak memiliki pelanggan\n");
          sleep(2);
        } else{
          AddOrder(&current_room, mejap, &Order);
        }
      } else if(strcmp(command, "PUT") == 0){

      } else if(strcmp(command, "TAKE") == 0){
        TakeFood(&Hand, Ruangann(current_room), player);
        sleep(1.5);
      } else if(strcmp(command, "CH") == 0){
        EmptyHand(&Hand);
      } else if(strcmp(command, "CT") == 0){
        EmptyTray(&Tray);
      } else if(strcmp(command, "PLACE") == 0){
        PlaceCustomer(&current_room, &antrian, player);
      } else if(strcmp(command, "GIVE") == 0){

      } else if(strcmp(command, "RECIPE") == 0){
        PrintTree(resep, 2);
        sleep(5);
      } else if(strcmp(command, "SAVE") == 0){

      } else if(strcmp(command, "LOAD") == 0){

      } else if(strcmp(command, "LEGEND") == 0){
        Legend();
        sleep(2);
      } else if(strcmp(command, "EXIT") == 0){
        clrscr();
        printf("GAME OVER\n");
        //Credit();
        sleep(1.5);
        exit(0);
      } else if (strcmp(command, "PTRAY") == 0){
        PrintStack(Tray);
        sleep(5);
      } else if (strcmp(command, "PHAND") == 0){
        PrintStack(Hand);
        sleep(5);
      } else if (strcmp(command, "PQUEUE") == 0){
        PrintQueue(antrian);
        sleep(5);
      } else if (strcmp(command, "PARRAY") == 0){
        TulisIsiArray(Order);
        sleep(5);
      }

      if(strcmp(command, "RECIPE") != 0 && strcmp(command, "SAVE") != 0 && strcmp(command, "LOAD") != 0 && strcmp(command, "LEGEND") != 0){
        EveryTurn(&MAP, &life, &time, &Order, &antrian);
      }
    }
    printf("GAME OVER\n");
    //Credit();
    sleep(1.5);
    exit(0);
  }
  return 0;
}
