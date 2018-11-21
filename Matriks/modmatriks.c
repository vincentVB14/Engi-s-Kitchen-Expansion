// BODY dari ADT MATRIKS

#include "modmatriks.h"
#include "../Point/modpoint.c"
#include "../Mesin/modmesinkar.c"
#include "../Mesin/modmesinkata.c"
#include <stdio.h>
#include <string.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void modMakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  // KAMUS LOKAL

  // ALGORITMA
  NBrsEff (*M) = NB;
  NKolEff (*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMatrix (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrsMatrix (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (BrsMin);
}

indeks GetFirstIdxKolMatrix (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (KolMin);
}

indeks GetLastIdxBrsMatrix (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (GetFirstIdxBrsMatrix (M) + NBrsEff (M) - 1);
}

indeks GetLastIdxKolMatrix (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (GetFirstIdxKolMatrix (M) + NKolEff (M) - 1);
}

boolean IsIdxEffMatrix (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (i >= GetFirstIdxBrsMatrix (M) && i <= GetLastIdxBrsMatrix (M) &&
          j >= GetFirstIdxKolMatrix (M) && j <= GetLastIdxKolMatrix (M));
}

void modTulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA

  for (i = GetFirstIdxBrsMatrix(M); i <= GetLastIdxBrsMatrix(M); i++)
  {
    printf(" ");
    for (j = GetFirstIdxKolMatrix(M); j <= GetLastIdxKolMatrix(M); j++)
    {
      switch(MElmt(M,i,j))
      {
        case ('P'):     // Player
        {
          printf("P");
          break;
        }
        case ('L'):     // Lantai
        {
          printf(" ");
          break;
        }
        case ('X'):    // Kursi
        {
          if (MElmt2(M,i,j))
          {
            printf("C");
          }
          else
          {
            printf("X");
          }
          break;
        }
        case ('M'):       // Meja Customer
        {
          printf("%s", MElmt3(M,i,j));
          break;
        }
        default:          // Useless
        {
          printf("Z");
          break;
        }
      }
      if (j != GetLastIdxKolMatrix(M))
      {
        printf(" | ");
      }
      else if (i != GetLastIdxBrsMatrix(M))
      {
        printf("\n");
        for (int k = 1; k <= NBrsEff(M); k++)
        {
          printf("----");
        }
        printf("\n");
      }
    }
  }
  printf("\n");
}

void modTulisMATRIKSDapur (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA

  for (i = GetFirstIdxBrsMatrix(M); i <= GetLastIdxBrsMatrix(M); i++)
  {
    printf(" ");
    for (j = GetFirstIdxKolMatrix(M); j <= GetLastIdxKolMatrix(M); j++)
    {
      switch(MElmt(M,i,j))
      {
        case ('P'):
        {
          printf("P");
          break;
        }
        case ('L'):
        {
          printf(" ");
          break;
        }
        case ('T'):
        {
          printf("T");
          break;
        }
        case ('M'):
        {
          printf("M");
          break;
        }
        default:
        {
          printf("Z");
          break;
        }
      }
      if (j != GetLastIdxKolMatrix(M))
      {
        printf(" | ");
      }
      else if (i != GetLastIdxBrsMatrix(M))
      {
        printf("\n");
        for (int k = 1; k <= NBrsEff(M); k++)
        {
          printf("----");
        }
        printf("\n");
      }
    }
  }
}

void MejaKursi (MATRIKS *M)
/* Mengisi hubungan antara kursi dan meja */
{
  // KAMUS LOKAL
  int count;
  int i,j;

  // ALGORITMA
  for (i = GetFirstIdxBrsMatrix(*M); i <= GetLastIdxBrsMatrix(*M); i++)
  {
    for (j = GetFirstIdxKolMatrix(*M); j <= GetLastIdxKolMatrix(*M); j++)
    {
      if (MElmt(*M,i,j) == 'M')
      {
        count = 0;
        if (MElmt(*M,(i-1),j) == 'X')
        {
          count++;
          strcpy(MElmt3(*M,(i-1),j), MElmt3(*M,i,j));
        }
        if (MElmt(*M,(i+1),j) == 'X')
        {
          count++;
          strcpy(MElmt3(*M,(i+1),j), MElmt3(*M,i,j));
        }
        if (MElmt(*M,i,(j-1)) == 'X')
        {
          count++;
          strcpy(MElmt3(*M,i,(j-1)), MElmt3(*M,i,j));
        }
        if (MElmt(*M,i,(j+1)) == 'X')
        {
          count++;
          strcpy(MElmt3(*M,i,(j+1)), MElmt3(*M,i,j));
        }
        MElmt4(*M,i,j) = count;
      }
    }
  }
}

void ReduceKesabaranM (MATRIKS *M, int *life)
/* Mengurangi kesabaran setiap meja yang mengandung pelanggan */
/* MElmt5 dari matriks merupakan jumlah kesabaran dari matriks */
{
  // KAMUS LOKAL
  int i, j;

  // ALGORITMA
  for (i = GetFirstIdxBrsMatrix(*M); i <= GetLastIdxBrsMatrix(*M); i++)
  {
    for (j = GetFirstIdxKolMatrix(*M); j <= GetLastIdxKolMatrix(*M); j++)
    {
      if ((MElmt(*M,i,j) == 'M') && (MElmt2(*M,i,j)))
      {
        MElmt5(*M,i,j)--;
        if (MElmt5(*M,i,j) == 0)
        {
          if ((MElmt(*M,(i-1),j) == 'X') && (MElmt2(*M,(i-1),j)))
          {
            MElmt2(*M,(i-1),j) = false;
            MElmt5(*M,(i-1),j) = MNil;
          }
          if ((MElmt(*M,(i+1),j) == 'X') && (MElmt2(*M,(i+1),j)))
          {
            MElmt2(*M,(i+1),j) = false;
            MElmt5(*M,(i+1),j) = MNil;
          }
          if ((MElmt(*M,i,(j-1)) == 'M') && (MElmt2(*M,i,(j-1))))
          {
            MElmt2(*M,i,(j-1)) = false;
            MElmt5(*M,i,(j-1)) = MNil;
          }
          if ((MElmt(*M,i,(j+1)) == 'M') && (MElmt2(*M,i,(j+1))))
          {
            MElmt2(*M,i,(j+1)) = false;
            MElmt5(*M,i,(j+1)) = MNil;
          }
          *life--;
        }
      }
    }
  }
}


void CountBarisKolom (int *Brs, int *Kol, char * filename)
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */
{
  // KAMUS LOKAL
  int i, j;

  // ALGORITMA

  // Inisialisasi
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
  if (found)
  {
    P = MakePOINT(j, i);
  }
  else
  {
    P = MakePOINT(0,0);
  }

  return (P);
}

POINT PosisiMeja(MATRIKS M, char* str)
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
      if (strcmp(MElmt3(M,i,j),str) == 0)
      {
        found = true;
      }
    }
  }
  P = MakePOINT(j, i);
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

POINT MejaDekatPlayer (MATRIKS M, POINT Player)
// Mencari meja yang dekat dengan player
// Mengembalikan nomor meja yang berada di dekat player
{
  // KAMUS LOKAL
  indeks i, j;
  POINT PMeja;

  // ALGORIMA
  i = Ordinat(Player);
  j = Absis(Player);

  if (MElmt(M,(i-1),j) == 'X')
  {
    return (PosisiMeja(M, MElmt3(M,(i-1),j)));
  }
  else if (MElmt(M,(i+1),j) == 'X')
  {
    return (PosisiMeja(M, MElmt3(M,(i+1),j)));
  }
  else if (MElmt(M,i,(j-1)) == 'X')
  {
    return (PosisiMeja(M, MElmt3(M,i,(j-1))));
  }
  else if (MElmt(M,i,(j+1)) == 'X')
  {
    return (PosisiMeja(M, MElmt3(M,i,(j+1))));
  }
  else
  {
    return (MakePOINT(0,0));
  }
}

POINT MejaDapurDekatPlayer (MATRIKS M, POINT Player)
// Mencari meja dapur yang dekat dengan player
// Mengembalikan posisi meja dapur di dekat player
{
  // KAMUS LOKAL
  indeks i,j;

  // ALGORITMA
  if (MElmt(M,(i-1),j) == 'M')
  {
    return (MakePOINT(j,(i-1)));
  }
  else if (MElmt(M,(i+1),j) == 'M')
  {
    return (MakePOINT(j,(i+1)));
  }
  else if (MElmt(M,i,(j-1)) == 'M')
  {
    return (MakePOINT((j-1),i));
  }
  else if (MElmt(M,i,(j+1)) == 'M')
  {
    return (MakePOINT((j+1),i));
  }
  else
  {
    return (MakePOINT(0,0));
  }
}
