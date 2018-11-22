#include "interface.c"
#include "Mesin/modmesinkar.c"
#include "Mesin/modmesinkata.c"
#include "Mesin/modmesintree.c"
//#include "modpoint.c"
#include "Queue/modqueue.c"
#include "Stack/modstackt.c"
#include "Graph/modgraph.c"
#include "Tree/modpohon.c"
//#include "game_mechanic.c"
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

void NewGame(char * playername)
/*Prosedur untuk menginput nama player*/
/*I.S. Player belum memiliki nama*/
/*F.S. Player memiliki nama dan memanggil StartGame()*/
{
  printf("Masukkan nama player (<12 karakter): ");
  scanf("%s", playername);
  printf("Selamat bermain, %s!", playername);
}

void StartGame(char * playername)
/*Prosedur untuk memulai permainan*/
/*I.S. Mengecek apakah player sudah memiliki nama. Jika belum, memanggil NewGame(). Jika sudah, memulai permainan*/
/*F.S. Game selesai dengan life player == 0, kemudian menampilkan Credit()*/
{
  if(strcmp(playername,"") == 0){
    printf("Nama player belum ada!\n");
    NewGame(playername);
  }
}

void EveryTurn (Graph *G, int *Life, int *Time, Queue*Q)
// Melakukan apa yang dilakukan pada setiap turn
// Mengurangi kesabaran setiap orang di meja
// Menambahkan waktu
// Mengeluarkan setiap pelanggan yang kesabarannya mencapai 0
// Megurangi kesabaran setiap pelanggan yang menunggu di Queue
{
  // KAMUS LOKAL

  // ALGORITMA
  *Time = *Time + 1;
  ReduceKesabaranG (G, Life);
}

void TakeFood(Stack * Hand, MATRIKS room, POINT Player)
/*Prosedur untuk mengambil makanan dan menambahkannya ke Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak penuh*/
/*F.S. Top dari Stack Hand berupa makanan di samping player*/
{
  POINT Meja_dapur = MejaDapurDekatPlayer(room, Player);
  if(!IsFullStack(*Hand)){
    if(Absis(Meja_dapur) != 0 && Ordinat(Meja_dapur) != 0){
      if(strcmp(MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)), "AyamGoreng") == 0){
        strcpy(MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)), "Ayam Goreng");
      }
      if(strcmp(MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)), "EsKrim") == 0){
        strcpy(MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)), "Es Krim");
      }
      printf("Anda mengambil %s\n", MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)));
      Push(Hand, MElmt3(room, Absis(Meja_dapur), Ordinat(Meja_dapur)));
    } else{
      printf("Tidak ada makanan yang bisa diambil\n");
    }
  } else{
    printf("Tangan sudah penuh\n");
  }
}

void EmptyHand(Stack * Hand)
/*Prosedur untuk mengosongkan Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak kosong*/
/*F.S. Stack Hand kosong*/
{
  printf("Membuang makanan di tangan...\n");
  sleep(1);
  CreateEmptyStack(Hand);
}

void EmptyTray(Stack * Tray)
/*Prosedur untuk mengosongkan Stack Tray*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Stack Tray kosong*/
{
  printf("Membuang makanan di tangan...\n");
  sleep(1);
  CreateEmptyStack(Tray);
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

  Stack Hand;
  Stack Tray;
  command = (char *) malloc (6 * sizeof(char)); //Alokasi string command sepanjang 6 karakter
  playername = (char *) malloc (12 * sizeof(char)); //Alokasi nama player sepanjang 12 karakter
  strcpy(playername,""); //Inisialisasi string nama player

  //Create Empties
  CreateEmptyStack(&Hand);
  CreateEmptyStack(&Tray);
  CreateEmptyQueue(&antrian, 5);
  CreateEmptyGraph(&MAP);
  BacaPeta(&MAP, &player);
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
        //AddQueue
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

      } else if(strcmp(command, "PUT") == 0){

      } else if(strcmp(command, "TAKE") == 0){
        TakeFood(&Hand, Ruangann(current_room), player);
        sleep(1.5);
      } else if(strcmp(command, "CH") == 0){
        EmptyHand(&Hand);
      } else if(strcmp(command, "CT") == 0){
        EmptyTray(&Tray);
      } else if(strcmp(command, "PLACE") == 0){

      } else if(strcmp(command, "GIVE") == 0){

      } else if(strcmp(command, "RECIPE") == 0){

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
      }

      if(strcmp(command, "RECIPE") != 0 && strcmp(command, "SAVE") != 0 && strcmp(command, "LOAD") != 0 && strcmp(command, "LEGEND") != 0){
        EveryTurn(&MAP, &life, &time, &antrian);
      }
    }
    printf("GAME OVER\n");
    //Credit();
    sleep(1.5);
    exit(0);
  }
  return 0;
}
