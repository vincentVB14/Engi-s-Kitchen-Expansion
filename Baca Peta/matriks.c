/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : matriks.c
   Topik        : ADT Program
   Tanggal      : 20 September 2018
   Deskripsi    : Mengimplementasikan fungsi-fungsi dari matriks.h */

// BODY dari ADT MATRIKS

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
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
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (GetFirstIdxBrs (M) + NBrsEff (M) - 1);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (GetFirstIdxKol (M) + NKolEff (M) - 1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (i >= GetFirstIdxBrs (M) && i <= GetLastIdxBrs (M) &&
          j >= GetFirstIdxKol (M) && j <= GetLastIdxKol (M));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  MakeMATRIKS (NBrsEff (MIn), NKolEff(MIn), MHsl);

  for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++)
  {
    for (j = GetFirstIdxKol (MIn); j <= GetLastIdxKol (MIn); j++)
    {
      MElmt (*MHsl, i, j) = MElmt (MIn, i, j);
    }
  }
}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  MakeMATRIKS (NB, NK, M);

  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
  {
    for (j = GetFirstIdxKol (*M); j <= GetLastIdxKol (*M); j++)
    {
      scanf ("%c", &MElmt (*M, i, j));
    }
    scanf ("\n");
  }
}

void TulisMATRIKS (MATRIKS M)
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

  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
  {
    for (j = GetFirstIdxKol (M); j < GetLastIdxKol (M); j++)
    {
      printf ("%c", MElmt (M, i, j));
    }

    if (i != GetLastIdxBrs (M))
    {
      printf ("%c", MElmt (M, i, GetLastIdxKol (M)));
      printf ("\n");
    }
    else
    {
      printf ("%c", MElmt (M, i, GetLastIdxKol (M)));
    }
  }
}
