#include "interface.c"
//#include "modmatriks.c"
//#include "modmesinkar.c"
//#include "modmesinkata.c"
//#include "modpoint.c"
//#include "modqueue.c"
#include "BacaMap.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void EveryTurn (MATRIKS *M, int *Life, int *Time, Queue*Q)
// Melakukan apa yang dilakukan pada setiap turn
// Mengurangi kesabaran setiap orang di meja
// Menambahkan waktu
// Mengeluarkan setiap pelanggan yang kesabarannya mencapai 0
// Megurangi kesabaran setiap pelanggan yang menunggu di Queue
{
  // KAMUS LOKAL

  // ALGORITMA
  *Time = *Time + 1;
  ReduceKesabaranM (M, Life);
}

////////////////////////////////////////////////////////////////////////////////////////

int main(){
  clrscr();
  int choice;
  int brs1, brs2, brs3, brs4, kol1, kol2, kol3, kol4;
  int money, life, time;
  char *command;
  char *playername;
  MATRIKS ruang1;
  MATRIKS dapur;
  POINT player;
  POINT mejap;
  Queue antrian;
  command = (char *) malloc (6 * sizeof(char)); //Alokasi string command sepanjang 6 karakter
  playername = (char *) malloc (12 * sizeof(char)); //Alokasi nama player sepanjang 12 karakter
  strcpy(playername,""); //Inisialisasi string nama player

  CreateEmptyQueue(&antrian, 5);
  CountBarisKolom(&brs1, &kol1, "File Eksternal/Ruang1.txt");
  //CountBarisKolom(&brs2, &kol2, "Ruang2.txt");
  //CountBarisKolom(&brs3, &kol3, "Ruang3.txt");
  CountBarisKolom(&brs4, &kol4, "File Eksternal/Dapur.txt");

  money = 1000;
  life = 24;
  time = 0;

  // Membuat MATRIKS Ruang dan Dapur
  if (IsIdxValidMatrix(brs1, kol1))
  {
    modMakeMATRIKS(brs1, kol1, &ruang1);
    modMakeMATRIKS(brs4, kol4, &dapur);
    printf("Pembentukan matriks berhasil\n");
  }
  else
  {
    printf("Pembentukan matriks gagal\n");
  }

  // Kopi semua elemen ke dalam matriks
  FileKeMatriks(&ruang1, "File Eksternal/Ruang1.txt");
  FileKeMatriksDapur(&dapur, "File Eksternal/Dapur.txt");

  MejaKursi(&ruang1);
  player = PosisiPlayer(ruang1);
  mejap = MakePOINT(0,0);
  clrscr();
  MainMenu();
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
      printf("Pilihan salah. Exiting program...");
      exit(0);
    }
  }
  sleep(1.5);
  if(choice == 1 || choice == 2 || choice == 3){
    while(life > 0){
      clrscr();
      mejap = MejaDekatPlayer(ruang1, player);
      printf("Time = %d\n", time);
      printf("Meja dekat player : ");
      TulisPOINT(mejap);
      printf("\n");
      Play(playername, money, life, time);
      //TulisRoom();
      //TulisPOINT(player);
      modTulisMATRIKS(ruang1);
      printf(">>> ");
      scanf("%s", command);
      if(strcmp(command, "GU") == 0){
        GoUP(&ruang1, &player);
        EveryTurn(&ruang1, &life, &time, &antrian);
      } else if(strcmp(command, "GD") == 0){
        GoDOWN(&ruang1, &player);
        EveryTurn(&ruang1, &life, &time, &antrian);
      } else if(strcmp(command, "GL") == 0){
        GoLEFT(&ruang1, &player);
        EveryTurn(&ruang1, &life, &time, &antrian);
      } else if(strcmp(command, "GR") == 0){
        GoRIGHT(&ruang1, &player);
        EveryTurn(&ruang1, &life, &time, &antrian);
      } else if(strcmp(command, "ORDER") == 0){

      } else if(strcmp(command, "PUT") == 0){

      } else if(strcmp(command, "TAKE") == 0){

      } else if(strcmp(command, "CH") == 0){

      } else if(strcmp(command, "CT") == 0){

      } else if(strcmp(command, "PLACE") == 0){

      } else if(strcmp(command, "GIVE") == 0){

      } else if(strcmp(command, "RECIPE") == 0){

      } else if(strcmp(command, "SAVE") == 0){

      } else if(strcmp(command, "LOAD") == 0){

      } else if(strcmp(command, "LEGEND") == 0){

      } else if(strcmp(command, "EXIT") == 0){
        clrscr();
        printf("GAME OVER\n");
        Credit();
        sleep(1.5);
        exit(0);
      }
    }
    printf("GAME OVER\n");
    Credit();
    sleep(1.5);
    exit(0);
  }
  return 0;
}
