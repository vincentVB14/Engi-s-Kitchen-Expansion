/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "kamus.h"

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
  Bintree temp = Resep;
  AddressTree P = Akar(temp);
  InverseStack(Hand);
  Pop(Hand, &X);
  if(X != Info(P)){
    EmptyHand(Hand);
  } else{
    while(!IsOneElmt(temp)){
      Pop(Hand, &X);
      if(X == Info(Left(P))){
        P = Left(P);
      } else if(X == Info(Right(P))){
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
