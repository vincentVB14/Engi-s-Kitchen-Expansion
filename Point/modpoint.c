/* Nama file    : point.c
   Topik        : ADT Program
   Tanggal      : 6 September 2018
   Deskripsi    : Mengimplementasikan ADT POINT dari point.h */

// BODY dari ADT POINT

// Definisi TYPE Point

#include "modpoint.h"
#include <math.h>
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
  // KAMUS LOKAL
  POINT P;

  // ALGORITMA
  Absis (P) = X;
  Ordinat (P) = Y;

  return (P);
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
  // KAMUS LOKAL

  // ALGORITMA
  printf ("<%d,%d>", Absis (P), Ordinat (P));
}
