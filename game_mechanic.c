/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "kamus.h"

void NewGame(char * playername)
/*Prosedur untuk menginput nama player*/
/*I.S. Player belum memiliki nama*/
/*F.S. Player memiliki nama dan memanggil StartGame()*/
{
  printf("Masukkan nama player (<12 karakter): ");
  scanf("%s", playername);
  printf("Selamat bermain, %s!", playername);
  StartGame();
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

void LoadGame();
/*Prosedur untuk load permainan dari file eksternal*/
/*I.S. Permainan belum dimulai*/
/*F.S. Permainan dimulai dengan kondisi yang sesuai dengan hasil simpanan di file eksternal*/

void TakeFood(Stack * Hand)
/*Prosedur untuk mengambil makanan dan menambahkannya ke Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak penuh*/
/*F.S. Top dari Stack Hand berupa makanan di samping player*/
{
  if(!IsFull(*Hand)){
    //X berisi makanan di samping player
    Push(Hand, X);
  }
}

void EmptyHand(Stack * Hand)
/*Prosedur untuk mengosongkan Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak kosong*/
/*F.S. Stack Hand kosong*/
{

  infotype X;
  while(!IsEmpty(*Hand)){
    Pop(Hand, &X)
  }
}

void EmptyTray(Stack * Tray)
/*Prosedur untuk mengosongkan Stack Tray*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Stack Tray kosong*/
{
  infotype X;
  while(!IsEmpty(*Tray)){
    Pop(Tray, &X)
  }
}

void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep)
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi*/
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */
{
  infotype X;
  Bintree P = Resep;
  InverseStack(Hand);
  Pop(Hand, &X);
  if(X != Akar(P)){
    EmptyHand(Hand);
  } else{
    while(!IsOneElmt(temp)){
      Pop(Hand, &X);
      if(X == Akar(Left(P))){
        P = Left(P);
      } else if(X == Akar(Right(P))){
        P = Right(P);
      } else{
        EmptyHand(Hand);
      }
    }
    if(!IsEmpty(*Hand)){
      Pop(Hand, &X);
      Push(Tray, X);
    }
  }
}

void GiveFood(Stack * Tray)
/*Prosedur untuk memberikan makan paling atas tumpukan*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Makanan paling atas di Stack Tray di-Pop*/
{
  if(!IsEmpty(*Tray)){
    infotype X;
    Pop(Tray, &X);
  }
}
