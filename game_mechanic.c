/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "game_mechanic.h"
#include "fakestring.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// PENGATURAN AWAL GAME

void NewGame(char * playername)
/*Prosedur untuk menginput nama player*/
/*I.S. Player belum memiliki nama*/
/*F.S. Player memiliki nama dan memanggil StartGame()*/
{
  FILE *save;

  save = fopen("savefile.txt", "w");
  printf("Masukkan nama player (<15 karakter): ");
  scanf("%s", playername);
  fprintf(save, "%s", playername);
  printf("Selamat bermain, %s!", playername);
  fclose(save);
}

void StartGame(char * playername)
/*Prosedur untuk memulai permainan*/
/*I.S. Mengecek apakah player sudah memiliki nama. Jika belum, memanggil NewGame(). Jika sudah, memulai permainan*/
/*F.S. Game selesai dengan life player == 0, kemudian menampilkan Credit()*/
{
  if(FakeStrCmp(playername,"") == 0){
    printf("Nama player belum ada!\n");
    NewGame(playername);
  }
}

// ATURAN-ATURAN REGULASI GAME
void EveryTurn (Graph *G, int *Life, int *Time, TabInt*O, Queue*Q)
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
  KurangSabarArray(O, Life);
}


// ATURAN STACK HAND DAN TRAY DALAM GAME

void TakeFood(Stack * Hand, Gaddress room, POINT Player, BinTree resep)
/*Prosedur untuk mengambil makanan dan menambahkannya ke Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak penuh*/
/*F.S. Top dari Stack Hand berupa makanan di samping player*/
{
  POINT Meja_dapur = MejaDapurDekatPlayer(Ruangann(room), Player);
  boolean check = true;
  if(!IsFullStack(*Hand)){
    if(Absis(Meja_dapur) != 0 && Ordinat(Meja_dapur) != 0){
      if(IsEmptyStack(*Hand)){
        if(FakeStrCmp(MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)), Akar(resep)) == 0){
          printf("Anda mengambil %s\n", MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)));
          Push(Hand, MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)));
        } else{
          printf("Anda belum mengambil Piring!\n");
        }
      } else{
        Stack Stemp;
        CopyStack(*Hand, &Stemp); //Copy Stack Hand ke Stack Stemp untuk penyimpanan temporary
        InverseStack(&Stemp); //Stack Stemp diinverse sehingga bisa dipop dari elemen pertama yang dimasukkan ke Stack
        BinTree temp;
        MakeTree(Akar(resep), Left(resep), Right(resep), &temp); //Copy BinTree resep ke BinTree temp
        FakeStrCpy(Akar(temp), Akar(resep));
        char * X;
        X = (char *) malloc (34 * sizeof(char)); //Alokasi panjang string untuk X
        while(!IsEmptyStack(Stemp)){
          Pop(&Stemp, &X);
          if(FakeStrCmp(X, Akar(temp)) == 0){
            if(SearchTree(Left(temp), MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)))){ //Jika yang mau diambil ada di kiri
              temp = Left(temp);
            } else{ //Jika tidak, ke kanan
              temp = Right(temp);
            }
          } else{
            check = false;
            break;
          }
        }
        if(check){
          if(FakeStrCmp(MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)), Akar(temp)) == 0){ //Jika hasil yang dicari sama dengan akar pohon
            printf("Anda mengambil %s\n", MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)));
            Push(Hand, MElmt3(Ruangann(room), Absis(Meja_dapur), Ordinat(Meja_dapur)));
          } else{
            printf("Anda tidak bisa mengambil makanan ini!\n");
          }
        } else{
          printf("Anda tidak bisa mengambil makanan ini!\n");
        }
      }
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
  CreateEmptyStack(Hand);
}

void EmptyTray(Stack * Tray)
/*Prosedur untuk mengosongkan Stack Tray*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Stack Tray kosong*/
{
  printf("Membuang makanan di tray...\n");
  CreateEmptyStack(Tray);
}

void CreateFood(Stack * Hand, Stack * Tray, Gaddress room, POINT Player, BinTree resep)
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi*/
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */
{
  POINT posisi_tray = TrayDekatPlayer(Ruangann(room), Player);
  if(!IsFullStack(*Tray)){
    if(Absis(posisi_tray) != 0 && Ordinat(posisi_tray) != 0){
      if(!IsEmptyStack(*Hand)){
        Stack Stemp;
        CopyStack(*Hand, &Stemp); //Copy Stack Hand ke Stack Stemp untuk penyimpanan temporary
        InverseStack(&Stemp); //Stack Stemp diinverse sehingga bisa dipop dari elemen pertama yang dimasukkan ke Stack
        BinTree temp;
        MakeTree(Akar(resep), Left(resep), Right(resep), &temp); //Copy BinTree resep ke BinTree temp
        FakeStrCpy(Akar(temp), Akar(resep));
        char * X;
        X = (char *) malloc (34 * sizeof(char)); //Alokasi panjang string untuk X
        Pop(&Stemp, &X); //Pop Piring
        while(!IsEmptyStack(Stemp)){
          Pop(&Stemp, &X);
          if(SearchTree(Left(temp), X)){ //Jika yang mau diambil ada di kiri
            temp = Left(temp);
          } else{ //Jika tidak, ke kanan
            temp = Right(temp);
          }
        }
        if(FakeStrCmp(X, Akar(temp)) == 0 && IsTreeOneElmt(Left(temp))){
          CreateEmptyStack(Hand);
          printf("%s telah dibuat dan dimasukkan ke Tray\n", Akar(Left(temp)));
          Push(Tray, Akar(Left(temp)));
        } else{
          printf("Tidak ada makanan yang bisa dibuat 1\n");
        }
      } else{
        printf("Tidak ada makanan yang bisa dibuat 2\n");
      }
    } else{
      printf("Anda tidak berada di sebelah Tray\n");
    }
  } else{
    printf("Tray sudah penuh\n");
  }
}

// ATURAN QUEUE DALAM GAME

void PlaceCustomer(Gaddress *F, Queue *Q, POINT Pemain)
/* Prosedur untuk mendudukkan customer ke kursi */
/*I.S. Queue terdefinisi, mungkin kosong*/
/*F.S. Jika jumlah kursi yang ingin di-assign oleh customer
       sama dengan jumlah customer di Head Queue, maka elemen Queue berkurang 1 .
       Jika tidak, maka Queue tetap dan kursi dibiarkan kosong*/
{
  // KAMUS LOKAL
  POINT P;
  int i, j;
  customer X;
  // ALGORITMA
  P = MejaDekatPlayer(Ruangann(*F), Pemain);
  i = Ordinat(P);
  j = Absis(P);
  if (i != 0 && j != 0)
  {
    if (!MElmt2(Ruangann(*F), i, j))
    {
      if (MElmt4(Ruangann(*F), i, j) == 2)
      {
        DelQueue2(Q, &X);
      }
      else if (MElmt4(Ruangann(*F), i, j) == 4)
      {
        DelQueue(Q, &X);
      }
      if (InfoJumlah(X) != -1)
      {
        int Sabar = rand() % (99 + 1 - 80) + 80;
        MElmt5(Ruangann(*F), i, j) = Sabar;
        MElmt2(Ruangann(*F), i, j) = true;
        MElmt2(Ruangann(*F), i, j - 1) = true;
        MElmt2(Ruangann(*F), i, j + 1) = true;
        if (InfoJumlah(X) == 4){
          MElmt2(Ruangann(*F), i-1, j) = true;
          MElmt2(Ruangann(*F), i+1, j) = true;
        }
      }
      else
      {
        printf("Tidak ada kelompok di antrian dengan jumlah orang sama dengan jumlah kursi\n");
        sleep(2);
      }
    }
    else
    {
      printf("Kursi di meja ini penuh\n");
      sleep(2);
    }
  }
  else
  {
    printf("Tidak ada kursi di sebelah anda\n");
    sleep(2);
  }
}

void GiveFood(Gaddress *F, Stack * Tray, TabInt *O, POINT Player, int *money)
/*Prosedur untuk memberikan makan paling atas tumpukan*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Makanan paling atas di Stack Tray di-Pop*/
{
  POINT P;
  int i;
  int j;
  P = MejaDekatPlayer(Ruangann(*F),Player);
  i = Ordinat(P);
  j = Absis(P);
  if (i == 0 && j == 0){
    printf("Tidak ada meja di dekat anda\n");
  }
  else{
    if (!MElmt2(Ruangann(*F),i,j)){
      printf("Tidak ada pelanggan di meja tersebut\n");
    }
    else {
      int index;
      index = SearchArray(*O,FakeAtoi(MElmt3(Ruangann(*F),Ordinat(P),Absis(P))));
      if (No(*O,index) != FakeAtoi(MElmt3(Ruangann(*F),Ordinat(P),Absis(P))))
      {
        printf("Pelanggan di meja tersebut belum memesan makanan\n");
      }
      else {
        if (!IsEmptyStack(*Tray))
        {
          infostack X;
          Pop(Tray, &X);
          if (FakeStrCmp(X,Food(*O,index)) != 0){
            printf("Meja ini tidak memesan makanan di atas tumpukan tray\n");
            Push(Tray, X);
          }
          else {
            MElmt2(Ruangann(*F),i,j) = false;
            MElmt2(Ruangann(*F), i, j - 1) = false;
            MElmt2(Ruangann(*F), i, j + 1) = false;
            if (MElmt4(Ruangann(*F),i,j) == 4){
              MElmt2(Ruangann(*F), i-1, j) = false;
              MElmt2(Ruangann(*F), i+1, j) = false;
            }
            ElType Temp;
            DelEli(O,index,&Temp);
            if (FakeStrCmp(X,"Spaghetti Bolognese") == 0){
              *money += 200;
            }
            else {
              *money += 100;
            }
          }
        }
      }
    }
  }
}

// ATURAN ARRAY DALAM GAME
boolean SearchNoMejaArray (TabInt T, int n)
/* Mengecek apakah meja tersebut sudah memesan */
{
	//Kamus
	IdxType i;
	boolean found;

	//Algoritma
	found = false;
	if (!IsEmptyArray(T))
	{
		i = GetFirstIdxArray(T);
		while ((i <= GetLastIdxArray(T)) && (!found))
		{
			if (No(T,i) == n)
			{
				found = true;
			}
			else
			{
				i++;
			}
		}
	}
	return (found);
}

int SearchArray (TabInt T, int n)
/* Mengembalikan no meja untuk give */
{
	//Kamus
	IdxType i;
	boolean found;
 	//Algoritma
	found = false;
	if (!IsEmptyArray(T))
	{
		i = GetFirstIdxArray(T);
		while ((i <= GetLastIdxArray(T)) && (!found))
		{
			if (No(T,i) == n)
			{
				found = true;
			}
			else
			{
				i++;
			}
		}
	}
	return (i);
}

void AddOrder (Gaddress *M, POINT P, TabInt *O)
/* Menerima pesanan customer */
{
	//Kamus
	int i;
	int f;
  int e;
  int g;

	//Algoritma
	if (IsFullArray(*O))
	{
		printf("Tidak dapat menerima pesanan\n");
    sleep(2);
	}
	else if (SearchNoMejaArray(*O,FakeAtoi(MElmt3(Ruangann(*M),Ordinat(P),Absis(P)))))
	{
		printf("Order sudah dilakukan\n");
    sleep(2);
	} else {
		i = GetLastIdxArray(*O) + 1;
		No(*O,i) = FakeAtoi(MElmt3(Ruangann(*M),Ordinat(P),Absis(P)));
    e = rand() % (8 + 1);
		f = rand() % (8 + 1);
    g = ((e * f) % 8) + 1;
		switch (g)
		{
			case 1 :
			{
				FakeStrCpy(Food(*O,i),"Banana Split");
				break;
			}
			case 2 :
			{
				FakeStrCpy(Food(*O,i),"Sundae");
				break;
			}
			case 3 :
			{
				FakeStrCpy(Food(*O,i),"Nasi Telur Dadar");
				break;
			}
			case 4 :
			{
				FakeStrCpy(Food(*O,i),"Nasi Ayam Goreng");
				break;
			}
			case 5 :
			{
				FakeStrCpy(Food(*O,i),"Burger");
				break;
			}
			case 6 :
			{
				FakeStrCpy(Food(*O,i),"Hot Dog");
				break;
			}
			case 7 :
			{
				FakeStrCpy(Food(*O,i),"Spaghetti Bolognese");
				break;
			}
			case 8 :
			{
				FakeStrCpy(Food(*O,i),"Spaghetti Carbonara");
				break;
			}
		}
		Kesabaran(*O,i) = MElmt5(Ruangann(*M),Ordinat(P),Absis(P));
		Neff(*O)++;
	}
}

void DelOrder (TabInt *O)
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

// ATURAN PERGERAKAN DALAM GAME

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
