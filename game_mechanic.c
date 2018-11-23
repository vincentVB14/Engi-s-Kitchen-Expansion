/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "game_mechanic.h"
#include <string.h>

// PENGATURAN AWAL GAME

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

void LoadGame();
/*Prosedur untuk load permainan dari file eksternal*/
/*I.S. Permainan belum dimulai*/
/*F.S. Permainan dimulai dengan kondisi yang sesuai dengan hasil simpanan di file eksternal*/


// ATURAN-ATURAN REGULASI GAME
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
  KurangSabarQueue (Q, Life);
}


// ATURAN STACK HAND DAN TRAY DALAM GAME

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

//void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep)
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi*/
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */
/*{
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
}*/

void GiveFood(Stack * Tray)
/*Prosedur untuk memberikan makan paling atas tumpukan*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Makanan paling atas di Stack Tray di-Pop*/
{
  if(!IsEmptyStack(*Tray)){
    infostack X;
    Pop(Tray, &X);
  }
}

// ATURAN ARRAY DALAM GAME

void AddOrder (MATRIKS *M, POINT P, TabInt *O, BinTree T)
/* Menerima pesanan customer */
{
	//Kamus
	int i;
	int N;
  int f;

	//Algoritma
	if (IsFullArray(*O))
	{
		printf("Tidak dapat menerima pesanan\n");
	}
	else
	{
		i = GetLastIdxArray(*O) + 1;
		No(*O,i) = atoi(MElmt3(*M,Absis(P),Ordinat(P)));
		f = rand() % (8 + 1);
		switch (f)
		{
			case 1 :
			{
				strcpy(Food(*O,i),"Banana Split");
				break;
			}
			case 2 :
			{
				strcpy(Food(*O,i),"Sundae");
				break;
			}
			case 3 :
			{
				strcpy(Food(*O,i),"Nasi Telur Dadar");
				break;
			}
			case 4 :
			{
				strcpy(Food(*O,i),"Nasi Ayam Goreng");
				break;
			}
			case 5 :
			{
				strcpy(Food(*O,i),"Burger");
				break;
			}
			case 6 :
			{
				strcpy(Food(*O,i),"Hot Dog");
				break;
			}
			case 7 :
			{
				strcpy(Food(*O,i),"Spaghetti Bolognese");
				break;
			}
			case 8 :
			{
				strcpy(Food(*O,i),"Spaghetti Carbonara");
				break;
			}
		}
		Kesabaran(*O,i) = MElmt5(*M,Absis(P),Ordinat(P));
		Neff(*O)++;
	}
}

void DelOrder (POINT P, TabInt *O)
/* Menerima pesanan customer */
{
	//Kamus
	ElType temp;
	int i;

	//Algoritma
	if(!IsEmptyArray(*O))
	{
		for(i = GetFirstIdxArray(*O); i <= GetLastIdxArray(*O); i++){
      if(Kesabaran(*O, i) == 0){
        DelEli(O,i, &temp);
      }
    }
	}
}
