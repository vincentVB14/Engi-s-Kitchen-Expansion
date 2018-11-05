// File lain yang digunakan
// Nasi uduk itu enak
#include "matriks.h"
#include "matriks.c"
#include "mesinkar.c"
#include "mesinkata.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountBarisKolom (int *Brs, int *Kol);
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */

void FileKeMatriks (MATRIKS *M);
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */

void CekSekelilingMeja (MATRIKS *M);
/* Mengecek ke sekeliling meja jumlah kursi dan apakah
   sudah terisi pelanggan atau belum */

void MejaKursi (MATRIKS *M);
/* Mengisi hubungan antara kursi dan meja */

void DelChar(Kata CKata, int n);
/* Menghapus beberapa elemen dari string*/

int main() {
  // KAMUS
  int Brs, Kol;
  MATRIKS Ruangan;

  // ALGORTIMA

  // Menghitung jumlah baris dan kolom untuk matriks
  CountBarisKolom(&Brs, &Kol);
  printf("\nBaris = %d\n", Brs);
  printf("Kolom = %d\n", Kol);

  // Membuat MATRIKS Ruangan
  if (IsIdxValid(Brs, Kol))
  {
    MakeMATRIKS(Brs, Kol, &Ruangan);
    printf("Matriks berhasil dibuat\n");
  }
  else
  {
    printf("Indeks tidak valid, matriks gagal\n");
  }

  // Kopi semua elemen ke dalam matriks
  FileKeMatriks(&Ruangan);

  // Cetak matriks
  printf("Menulis ruangan\n");
  TulisMATRIKS(Ruangan);
  printf("\n");

  return 0;
}

void CountBarisKolom (int *Brs, int *Kol)
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */
{
  // KAMUS LOKAL
  int i, j;

  // ALGORITMA

  // Inisialisasi
  STARTKATA();
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
      printf("%s", CKata);
    } else {
      i++;
      j = 0;
      printf("\n");
    }
    ADVKATA();
  }
  *Brs = i;
  *Kol = j;
}

void FileKeMatriks (MATRIKS *M)
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */
{
  // KAMUS LOKAL
  int i,j;

  // ALGORITMA

  // Inisialisasi
  STARTKATA();
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
        MElmt(*M,i,j) = 'L';
        MElmt2(*M,i,j) = false;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus player
      else if (strcmp(CKata, "Player") == 0)
      {
        MElmt(*M,i,j) = 'P';
        MElmt2(*M,i,j) = false;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus kursi
      else if (strcmp(CKata, "Kursi") == 0)
      {
        MElmt(*M,i,j) = 'X';
        MElmt2(*M,i,j) = false;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus meja pelanggan
      else if (strncmp(CKata, "Meja", 4) == 0)
      {
        MElmt(*M,i,j) = 'M';
        MElmt2(*M,i,j) = false;
        DelChar(CKata, 4);
        strcpy(MElmt3(*M,i,j), CKata);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus tray
      else if (strcmp(CKata, "Tray") == 0)
      {
        MElmt(*M,i,j) = 'T';
        MElmt2(*M,i,j) = false;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus meja dapur
      else if (strncmp(CKata, "N", 1) == 0)
      {
        MElmt(*M,i,j) = 'N';
        MElmt2(*M,i,j) = false;
        DelChar(CKata, 1);
        strcpy(MElmt3(*M,i,j), CKata);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus kursi terisi pelanggan
      else if (strcmp(CKata, "Customer") == 0)
      {
        MElmt(*M,i,j) = 'X';
        MElmt2(*M,i,j) = true;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
      // Kasus lain
      else
      {
        MElmt(*M,i,j) = 'Z';
        MElmt2(*M,i,j) = false;
        strcpy(MElmt3(*M,i,j), MNil2);
        MElmt4(*M,i,j) = MNil;
        MElmt5(*M,i,j) = MNil;
      }
    } else {
      i++;
      j = 0;
    }
    ADVKATA();
  }
}

void MejaKursi (MATRIKS *M)
/* Mengisi hubungan antara kursi dan meja */
{
  // KAMUS LOKAL

  // ALGORITMA

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
