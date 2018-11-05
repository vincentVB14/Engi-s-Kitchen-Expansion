// File lain yang digunakan
// Nasi uduk itu enak
#include "matriks.h"
#include "point.c"
#include "matriks.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountBarisKolom (int *Brs, int *Kol, char * filename);
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */

void FileKeMatriks (MATRIKS *M, char * filename);
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */

void FileKeMatriksDapur(MATRIKS *M, char * filename);
/* Mengkopi semua isi file ke dalam matriks dapur agar
  dapat diperlakukan sebagai matriks peta */


POINT PosisiPlayer(MATRIKS M);
/* Mencari posisi Player di dalam matriks */

void DelChar(Kata CKata, int n);
/* Menghapus beberapa elemen dari string*/

int main() {
  // KAMUS
  int Brs, Kol;
  MATRIKS Ruangan;
  MATRIKS Dapur;
  POINT Player;

  // ALGORTIMA

  // Menghitung jumlah baris dan kolom untuk matriks
  CountBarisKolom(&Brs, &Kol, "Ruang1.txt");

  // Membuat MATRIKS Ruangan
  if (IsIdxValidMatrix(Brs, Kol))
  {
    modMakeMATRIKS(Brs, Kol, &Ruangan);
    modMakeMATRIKS(Brs, Kol, &Dapur);
    printf("Matriks berhasil dibuat\n");
  }
  else
  {
    printf("Indeks tidak valid, matriks gagal\n");
  }

  // Kopi semua elemen ke dalam matriks
  FileKeMatriks(&Ruangan, "Ruang1.txt");
  FileKeMatriksDapur(&Dapur, "Dapur.txt");

  // Cetak matriks
  printf("Menulis ruangan\n");
  modTulisMATRIKS(Ruangan);
  printf("\n");
  MejaKursi(&Ruangan);
  Player = PosisiPlayer(Ruangan);
  printf("Posisi player di ruangan : ");
  TulisPOINT(Player);

  printf("\nMenulis dapur\n");
  modTulisMATRIKSDapur(Dapur);

  return 0;
}

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

void FileKeMatriks (MATRIKS *M, char * filename)
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */
{
  // KAMUS LOKAL
  int i,j;

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
      if (strcmp(CKata, "Lantai") == 0)
      {
        MElmt(*M,i,j) = 'L';            // Tipe lantai
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus player
      else if (strcmp(CKata, "Player") == 0)
      {
        MElmt(*M,i,j) = 'P';            // Tipe player
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus kursi
      else if (strcmp(CKata, "Kursi") == 0)
      {
        MElmt(*M,i,j) = 'X';            // Tipe kursi
        MElmt2(*M,i,j) = false;         // Belum ada Customer
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus meja pelanggan
      else if (strncmp(CKata, "Meja", 4) == 0)
      {
        MElmt(*M,i,j) = 'M';            // Tipe meja
        MElmt2(*M,i,j) = false;         // Belum ada Customer
        DelChar(CKata, 4);
        strcpy(MElmt3(*M,i,j), CKata);  // Identitas Meja
        MElmt4(*M,i,j) = MNil;          // Jumlah kursi di sekitar meja
        MElmt5(*M,i,j) = MNil;          // Kesabaran
      }
      // Kasus kursi terisi pelanggan
      else if (strcmp(CKata, "Customer") == 0)
      {
        MElmt(*M,i,j) = 'X';            // Tipe kursi
        MElmt2(*M,i,j) = true;          // Sudah ada Customer
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus lain
      else
      {
        MElmt(*M,i,j) = 'Z';            // Useless
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
}

void FileKeMatriksDapur(MATRIKS *M, char * filename)
/* Mengkopi semua isi file ke dalam matriks dapur agar
   dapat diperlakukan sebagai matriks peta */
{
  // KAMUS LOKAL
  int i,j;

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
      if (strcmp(CKata, "Lantai") == 0)
      {
        MElmt(*M,i,j) = 'L';            // Tipe lantai
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus player
      else if (strcmp(CKata, "Player") == 0)
      {
        MElmt(*M,i,j) = 'P';            // Tipe player
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus tray
      else if (strcmp(CKata, "Tray") == 0)
      {
        MElmt(*M,i,j) = 'T';            // Tipe tray
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus meja dapur
      else if (strncmp(CKata, "M", 1) == 0)
      {
        MElmt(*M,i,j) = 'M';            // Tipe meja dapur
        MElmt2(*M,i,j) = false;         // Useless
        DelChar(CKata, 1);              // Useless
        strcpy(MElmt3(*M,i,j), CKata);  // Jenis bahan di meja
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
      // Kasus lain
      else
      {
        MElmt(*M,i,j) = 'Z';            // Useless
        MElmt2(*M,i,j) = false;         // Useless
        strcpy(MElmt3(*M,i,j), MNil2);  // Useless
        MElmt4(*M,i,j) = MNil;          // Useless
        MElmt5(*M,i,j) = MNil;          // Useless
      }
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
}


POINT PosisiPlayer(MATRIKS M)
{
  // KAMUS LOKAL
  POINT P;
  int i,j;
  boolean found;

  // ALGORITMA
  i = GetFirstIdxBrsMatrix(M) - 1;
  j = GetFirstIdxKolMatrix(M) - 1;
  found = false;

  while (i < GetLastIdxBrsMatrix(M) && !found)
  {
    i++;
    j = GetFirstIdxKolMatrix(M) - 1;
    while (j < GetLastIdxKolMatrix(M) && !found)
    {
      j++;
      if (MElmt(M,i,j) == 'P')
      {
        found = true;
      }
    }
  }
  P = MakePOINT(i,j);
  return (P);
}

void DelChar(Kata CKata, int n)
/* Menghapus beberapa elemen dari string*/
{
  // KAMUS LOKAL
  int i, j;

  // ALGORITMA
  i = 0;
  for (j = n; j < strlen(CKata); j++)
  {
    CKata[i] = CKata[j];
    i++;
  }
  CKata[i] = '\0';
}
