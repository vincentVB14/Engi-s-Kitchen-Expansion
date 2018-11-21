/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "game_mechanic.h"

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

void CountBarisKolom (int *Brs, int *Kol, char * filename)
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */
{
  // KAMUS LOKAL
  int i, j;

  // ALGORITMA

  // Inisialisasi
  printf("Kata = %s", filename);
  STARTKATA(filename);
  if (EndKata) {
    i = 0;
  } else {
    i = 1;
  }
  j = 0;

  // Menghitung baris dan kolom
  while (!EndKata) {
    if (!NewLine) {
      j++;
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
  *Brs = i;
  *Kol = j;
}

void TakeFood(Stack * Hand, MATRIKS M, POINT Player)
/*Prosedur untuk mengambil makanan dan menambahkannya ke Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak penuh*/
/*F.S. Top dari Stack Hand berupa makanan di samping player*/
{
  POINT Meja_dapur;
  Meja_dapur = (MejaDapurDekatPlayer(M, Player));
  if(!IsFullStack(*Hand)){
    if(Absis(Meja_dapur) != 0 && Ordinat(Meja_dapur) != 0) {
      Push(Hand, MElmt3(M, Absis(Meja_dapur), Ordinat(Meja_dapur)));
    }
  }
}

void EmptyHand(Stack * Hand)
/*Prosedur untuk mengosongkan Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak kosong*/
/*F.S. Stack Hand kosong*/
{
  printf("Membuang makanan di tangan...\n");
  CreateEmptyStack(Hand);
}

void EmptyTray(Stack * Tray)
/*Prosedur untuk mengosongkan Stack Tray*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Stack Tray kosong*/
{
  printf("Membuang makanan di tangan...\n");
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

void AddOrder (MATRIKS *M, POINT P, TabInt *O, BinTree T)
/* Menerima pesanan customer */
{
	//Kamus
	int i;
	int N;

	//Algoritma
	if (IsFull(*O))
	{
		printf("Tidak dapat menerima pesanan\n");
	}
	else
	{
		i = GetLastIdx(*O) + 1;
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
	i = GetFirstIdx(*O);
	if (Kesabaran(*O,i) == 0)
	{
		DelEli(O, i, &temp);
	}
}

/* COMMAND LIST */
void GoUP(Graph *G, Gaddress *P, POINT *Player, boolean *valid)
/* Menaikkan player 1 tile ke atas kalau bisa */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  i = Ordinat(*Player);
  j = Absis(*Player);
  if (Ordinat(*Player) > GetFirstIdxBrsMatrix(Ruangann(*P)))
  {
    if (MElmt(Ruangann(*P),(i - 1),j) == 'L')
    {
      MElmt(Ruangann(*P),(i - 1),j) = 'P';
      MElmt(Ruangann(*P),i,j) = 'L';
      Ordinat(*Player) = Ordinat(*Player) - 1;
      *valid = true;
    }
    else
    {
      *valid = false;
    }
  }
  else
  {
    PindahRuangan(G, P, Player, valid);
  }
}

void GoDOWN(Graph *G, Gaddress *P, POINT *Player, boolean *valid)
/* Menaikkan player 1 tile ke bawah kalau bisa */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  i = Ordinat(*Player);
  j = Absis(*Player);
  if (Ordinat(*Player) < GetLastIdxBrsMatrix(Ruangann(*P)))
  {
    if (MElmt(Ruangann(*P),(i + 1),j) == 'L')
    {
      MElmt(Ruangann(*P),(i + 1),j) = 'P';
      MElmt(Ruangann(*P),i,j) = 'L';
      Ordinat(*Player) = Ordinat(*Player) + 1;
      *valid = true;
    }
    else
    {
      *valid = false;
    }
  }
  else
  {
    PindahRuangan(G, P, Player, valid);
  }
}

void GoLEFT(Graph *G, Gaddress *P, POINT *Player, boolean *valid)
/* Menggerakkan player 1 tile ke kiri kalau bisa */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  i = Ordinat(*Player);
  j = Absis(*Player);
  if (Absis(*Player) > GetFirstIdxKolMatrix(Ruangann(*P)))
  {
    if (MElmt(Ruangann(*P), i, (j - 1)) == 'L')
    {
      MElmt(Ruangann(*P),i, (j - 1)) = 'P';
      MElmt(Ruangann(*P),i,j) = 'L';
      Absis(*Player) = Absis(*Player) - 1;
      *valid = true;
    }
    else
    {
      *valid = false;
    }
  }
  else
  {
    PindahRuangan(G, P, Player, valid);
  }
}

void GoRIGHT(Graph *G, Gaddress *P, POINT *Player, boolean *valid)
/* Menggerakkan player 1 tile ke kanan kalau bisa */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  i = Ordinat(*Player);
  j = Absis(*Player);
  if (Absis(*Player) <  GetLastIdxKolMatrix(Ruangann(*P)))
  {
    if (MElmt(Ruangann(*P), i, (j + 1)) == 'L')
    {
      MElmt(Ruangann(*P),i, (j + 1)) = 'P';
      MElmt(Ruangann(*P),i,j) = 'L';
      Absis(*Player) = Absis(*Player) + 1;
      *valid = true;
    }
    else
    {
      *valid = false;
    }
  }
  else
  {
    PindahRuangan(G, P, Player, valid);
  }
}
