// BODY dari ADT GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modgraph.h"
#include "../tumbal.h"

// KONSTRUKTOR
void CreateEmptyGraph (Graph *G)
// Menciptakan graph kosong yang dapat digunakan
// Keterangan, first dari graph adalah GNil
{
  // KAMUS LOKAL

  // ALGORITMA
  FirstG(*G) = GNil;
  CurrentRoom(*G) = 0;
}

boolean IsEmptyGraph (Graph G)
// Mengirim true jika draf kosong
{
  // KAMUS LOKAL

  // ALGORITMA
  return (FirstG(G) == GNil);
}

boolean IsEmptyParent (Gaddress P)
// Mengirim true jika P adalah kosong
{
  // KAMUS LOKAL

  // ALGORITMA
  return (FirstChild(P) == GNil);
}

/****************** Manajemen Memori ******************/
Gaddress AlokasiGraph1 (int no, char *filename)
/* Mengirimkan address hasil alokasi sebuah elemen */
{
  // KAMUS LOKAL
  Gaddress P;
  indeks brs, kol;

  // ALGORITMA
  P = (Gaddress) malloc (sizeof(Ruangan));

  if (P != GNil)
  {
    CountBarisKolom(&brs, &kol, filename);
    Nomor(P) = no;
    modMakeMATRIKS(brs, kol, &Ruangann(P));
    NextP(P) = GNil;
    FirstChild(P) = GNil;
  }
  else
  {
    P = GNil;
  }
  return (P);
}

Gaddress2 AlokasiGraph2 (int no, POINT Prev, POINT Next)
/* Mengirimkan address hasil alokasi sebuah elemen */
{
  // KAMUS LOKAL
  Gaddress2 P;

  // ALGORITMA
  P = (Gaddress2) malloc (sizeof(NextRuangan));
  if (P != GNil)
  {
    NomorTarget(P) = no;
    PrevLoc(P) = Prev;
    NextLoc(P) = Next;
    NextChild(P) = GNil;
  }
  else
  {
    P = GNil;
  }
  return (P);
}

void DealokasiGraph1 (Gaddress *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  // KAMUS LOKAL

  // ALGORITMA
  free(*P);
}

void DealokasiGraph2 (Gaddress2 *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  // KAMUS LOKAL

  // ALGORITMA
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN GRAPH ******************/
Gaddress SearchRuangan (Graph G, int X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan GNil */
{
  // KAMUS LOKAL
  Gaddress P;

  // ALGORITMA
  if (IsEmptyGraph(G))
  {
    return GNil;
  }
  else
  {
    P = FirstG(G);
    while (NextP(P) != GNil && Nomor(P) != X)
    {
      P = NextP(P);
    }
    if (Nomor(P) == X)
    {
      return (P);
    }
    else
    {
      return GNil;
    }
  }
}

Gaddress2 SearchNextRuangan (Gaddress CurrP, POINT Player)
// Mencari apakah Player bisa pindah ke ruangan lain
// Jika dapat mengembalikan NextRuangan
// Jika tidak, mengembalikan GNil
{
  // KAMUS LOKAL
  Gaddress2 P;
  boolean found;

  // ALGORITMA
  P = FirstChild(CurrP);
  found = false;

  while (P != GNil && !found)
  {
    if ((Absis(Player) == Absis(PrevLoc(P))) && (Ordinat(Player) == Ordinat(PrevLoc(P))))
    {
      found = true;
    }
    else
    {
      P = NextChild(P);
    }
  }

  if (!found)
  {
    return GNil;
  }
  else
  {
    return P;
  }
}


/* PENAMBAHAN DAN PENGHAPUSAN ELEMEN GRAPH */
void AddRuangan (Graph *G, int no, char *filename)
/* Menambahkan ruangan ke dalam graf */
// Melakukan AddLast
{
  // KAMUS LOKAL
  Gaddress P, Last;

  // ALGORITMA
  P = AlokasiGraph1(no, filename);
  if (P != GNil)
  {
    if (IsEmptyGraph(*G))
    {
      FirstG(*G) = P;
    }
    else
    {
      Last = FirstG(*G);
      while (NextP(Last) != GNil)
      {
        Last = NextP(Last);
      }
      NextP(Last) = P;
    }
  }
}
void AddNextRuangan (Gaddress *P, int no, POINT Prev, POINT Next)
/* Menambahkan anak dari ruangan di graf yang berisi info ke next ruangan */
// Melakukan AddLast
{
  // KAMUS LOKAL
  Gaddress2 PChild, Last;

  // ALGORITMA
  PChild = AlokasiGraph2(no, Prev, Next);
  if (PChild != GNil)
  {
    if (IsEmptyParent(*P))
    {
      FirstChild(*P) = PChild;
    }
    else
    {
      Last = FirstChild(*P);
      while (NextChild(Last) != GNil)
      {
        Last = NextChild(Last);
      }
      NextChild(Last) = PChild;
    }
  }
}

/* PEMBACAAN FILE KE MATRIKS DAN GRAPH */
void FileToMatriks (Gaddress *P, char * filename)
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */
{
  // KAMUS LOKAL
  indeks i,j;
  POINT Prev,Next;

  // ALGORITMA

  // Inisialisasi
  STARTKATA(filename);
  // Cek file tidak kosong
  if (!EndKata)
  {
    i = 1;
    j = 0;
  }

  // Mengkopi isi file ke matriks
  while (!EndKata)
  {
    if (!NewLine) {
      j++;
      // Kasus lantai
      if (FakeStrCmp(CKata, "Lantai") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'L';            // Tipe lantai
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus player
      else if (FakeStrCmp(CKata, "Player") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'P';            // Tipe player
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus kursi
      else if (FakeStrCmp(CKata, "Kursi") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'X';            // Tipe kursi
        MElmt2(Ruangann(*P),i,j) = false;         // Belum ada Customer
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus meja pelanggan
      else if (FakeStrNCmp(CKata, "Meja", 4) == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'M';            // Tipe meja
        MElmt2(Ruangann(*P),i,j) = false;         // Belum ada Customer
        DelChar(CKata, 4);
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), CKata);  // Identitas Meja
        MElmt4(Ruangann(*P),i,j) = MNil;          // Jumlah kursi di sekitar meja
        MElmt5(Ruangann(*P),i,j) = MNil;          // Kesabaran
      }
      // Kasus kursi terisi pelanggan
      else if (FakeStrCmp(CKata, "Customer") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'X';            // Tipe kursi
        MElmt2(Ruangann(*P),i,j) = true;          // Sudah ada Customer
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus pintu
      else if (FakeStrNCmp(CKata, "Pintu", 5) == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'L';            // Tipe lantai
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
        // Memasukkan ruangan baru sebagai anak list
        DelChar(CKata,5);
        Prev = MakePOINT(j,i);
        if (i == GetFirstIdxBrsMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(j, GetLastIdxBrsMatrix(Ruangann(*P)));
        }
        else if (i == GetLastIdxBrsMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(j, GetFirstIdxBrsMatrix(Ruangann(*P)));
        }
        else if (j == GetFirstIdxKolMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(GetLastIdxKolMatrix(Ruangann(*P)), i);
        }
        else if (j == GetLastIdxKolMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(GetFirstIdxKolMatrix(Ruangann(*P)), i);
        }
        AddNextRuangan(P, FakeAtoi(CKata), Prev, Next);
      }
      // Kasus lain
      else
      {
        MElmt(Ruangann(*P),i,j) = 'Z';            // Useless
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
  MejaKursi(&Ruangann(*P));
}


void FileToMatriksDapur(Gaddress *P, char * filename)
/* Mengkopi semua isi file ke dalam matriks dapur agar
  dapat diperlakukan sebagai matriks peta */
{
  // KAMUS LOKAL
  int i,j;
  POINT Prev, Next;

  // ALGORITMA

  // Inisialisasi
  STARTKATA(filename);
  if (!EndKata)
  {
    i = 1;
    j = 0;
  }

  // Mengkopi isi file ke matriks
  while (!EndKata)
  {
    if (!NewLine) {
      j++;
      // Kasus lantai
      if (FakeStrCmp(CKata, "Lantai") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'L';            // Tipe lantai
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus player
      else if (FakeStrCmp(CKata, "Player") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'P';            // Tipe player
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus tray
      else if (FakeStrCmp(CKata, "Tray") == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'T';            // Tipe tray
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus meja dapur
      else if (FakeStrNCmp(CKata, "M", 1) == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'M';            // Tipe meja dapur
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        DelChar(CKata, 1);              // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), CKata);  // Jenis bahan di meja
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
      // Kasus pintu
      else if (FakeStrNCmp(CKata, "Pintu", 5) == 0)
      {
        MElmt(Ruangann(*P),i,j) = 'L';            // Tipe lantai
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
        // Memasukkan ruangan baru sebagai anak list
        DelChar(CKata,5);
        Prev = MakePOINT(j,i);
        if (i == GetFirstIdxBrsMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(j, GetLastIdxBrsMatrix(Ruangann(*P)));
        }
        else if (i == GetLastIdxBrsMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(j, GetFirstIdxBrsMatrix(Ruangann(*P)));
        }
        else if (j == GetFirstIdxKolMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(GetLastIdxKolMatrix(Ruangann(*P)), i);
        }
        else if (j == GetLastIdxKolMatrix(Ruangann(*P)))
        {
          Next = MakePOINT(GetFirstIdxKolMatrix(Ruangann(*P)), i);
        }
        AddNextRuangan(P, FakeAtoi(CKata), Prev, Next);
      }
      // Kasus lain
      else
      {
        MElmt(Ruangann(*P),i,j) = 'Z';            // Useless
        MElmt2(Ruangann(*P),i,j) = false;         // Useless
        FakeStrCpy(MElmt3(Ruangann(*P),i,j), MNil2);  // Useless
        MElmt4(Ruangann(*P),i,j) = MNil;          // Useless
        MElmt5(Ruangann(*P),i,j) = MNil;          // Useless
      }
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
}

// APLIKASI DI PROGRAM UTAMA
void BacaPeta (Graph *G, POINT *Player)
// Prosedur membaca peta dari file eksternal
{
  // KAMUS LOKAL
  Gaddress P;

  // ALGORITMA

  // Ruangan 1
  printf("Membaca ruang 1...\n");
  /*if( access("../File Eksternal/Ruang1.txt", F_OK ) != -1 ) {
      printf("File 1 ada\n");
  } else {
      printf("File 1 tidak ada\n");
  }*/

  AddRuangan(G, 1, "File Eksternal/Ruang1.txt");
  P = FirstG(*G);
  FileToMatriks(&P, "File Eksternal/Ruang1.txt");

  // Ruangan 2
  printf("Membaca ruang 2...\n");
  AddRuangan(G, 2, "File Eksternal/Ruang2.txt");
  P = NextP(P);
  FileToMatriks(&P, "File Eksternal/Ruang2.txt");

  // Ruangan 3
  printf("Membaca ruang 3...\n");
  AddRuangan(G, 3, "File Eksternal/Ruang3.txt");
  P = NextP(P);
  FileToMatriks(&P, "File Eksternal/Ruang3.txt");

  // Ruangan Dapur
  printf("Membaca ruang Dapur...\n");
  AddRuangan(G, 4, "File Eksternal/Dapur.txt");
  P = NextP(P);
  FileToMatriksDapur(&P, "File Eksternal/Dapur.txt");

  // Mencari posisi player
  P = FirstG(*G);
  while (CurrentRoom(*G) == 0 && P != GNil)
  {
    if (Absis(PosisiPlayer(Ruangann(P))) != 0)
    {
      *Player = PosisiPlayer(Ruangann(P));
      CurrentRoom(*G) = Nomor(P);
    }
    else
    {
      P = NextP(P);
    }
  }
}

void PindahRuangan (Graph *G, Gaddress *P, POINT *Player, boolean *valid)
// Memindahkan player dari suatu ruangan ke ruangan lainnya
{
  // KAMUS LOKAL
  Gaddress NextRuangan;
  Gaddress2 P2;

  // ALGORITMA
  P2 = SearchNextRuangan(*P, *Player);
  if (P2 != GNil)
  {
    NextRuangan = SearchRuangan(*G, NomorTarget(P2));
    if (NextRuangan != GNil)
    {
      *valid = true;
      // Set Lantai
      MElmt(Ruangann(*P), Ordinat(*Player), Absis(*Player)) = 'L';

      // Copy beberapa hal
      *P = NextRuangan;
      *Player = CopyPOINT(NextLoc(P2));
      CurrentRoom(*G) = NomorTarget(P2);

      // Set Player
      MElmt(Ruangann(*P), Ordinat(*Player), Absis(*Player)) = 'P';
    }
    else
    {
      *valid = false;
    }
  }
  else
  {
    *valid = false;
  }
}

void ReduceKesabaranG (Graph *G, int *life)
// Mengurangi kesabaran seluruh MAP
{
  // KAMUS LOKAL
  Gaddress P;

  // ALGORITMA
  P = FirstG(*G);
  while (P != GNil)
  {
    ReduceKesabaranM(&Ruangann(P), life);
    P = NextP(P);
  }
}



/*
// TESTER
int main()
{
  Graph Ruangans;
  POINT Player;
  Gaddress P;

  CreateEmptyGraph(&Ruangans);
  BacaPeta(&Ruangans, &Player);

  P = FirstG(Ruangans);
  printf("\n Ruangan 1 \n");
  modTulisMATRIKS(Ruangann(P));

  printf("\n Ruangan 2 \n");
  P = NextP(P);
  modTulisMATRIKS(Ruangann(P));

  printf("\n Ruangan 3 \n");
  P = NextP(P);
  modTulisMATRIKS(Ruangann(P));

  printf("\n Ruangan Dapur \n");
  P = NextP(P);
  modTulisMATRIKSDapur(Ruangann(P));

  printf("\n Sekarang player berada di : Ruangan %d \n", CurrentRoom(Ruangans));

}
*/
