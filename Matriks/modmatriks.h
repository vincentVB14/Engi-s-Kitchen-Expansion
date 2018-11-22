// HEADER dari ADT MATRIKS

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "../Point/modpoint.h"
#include "../Mesin/modmesinkata.h"

#define MNil -1
#define MNil2 "Nil"
#define MCharMax 20
/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 15
#define KolMin 1
#define KolMax 15

typedef struct {
	char tipe;
	boolean value1;
	char value2[MCharMax];
	int value3;
	int value4;
} TabElType;

typedef int indeks; /* indeks baris, kolom */
typedef struct {
	TabElType Mem[BrsMax+1][KolMax+1];
  int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void modMakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MElmt(M,i,j) (M).Mem[(i)][(j)].tipe
#define MElmt2(M,i,j) (M).Mem[(i)][(j)].value1
#define MElmt3(M,i,j) (M).Mem[(i)][(j)].value2
#define MElmt4(M,i,j) (M).Mem[(i)][(j)].value3
#define MElmt5(M,i,j) (M).Mem[(i)][(j)].value4

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMatrix (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrsMatrix (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKolMatrix (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrsMatrix (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKolMatrix (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEffMatrix (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

void modTulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

void modTulisMATRIKSDapur (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

void MejaKursi (MATRIKS *M);
/* Mengisi hubungan antara kursi dan meja */

void ReduceKesabaranM (MATRIKS *M, int *life);
/* Mengurangi kesabaran setiap meja yang mengandung pelanggan */
/* MElmt5 dari matriks merupakan jumlah kesabaran dari matriks */

void CountBarisKolom (int *Brs, int *Kol, char * filename);
/* Menghitung jumlah baris dan kolom untuk matriks
   dengan cara sekali melalui file eksternal */


POINT PosisiPlayer(MATRIKS M);
/* Mencari posisi Player di dalam matriks */

POINT PosisiMeja(MATRIKS M, char* str);
/* Mencari posisi Meja dengan identitas str */

void DelChar(Kata CKata, int n);
/* Menghapus beberapa elemen dari string*/

POINT MejaDekatPlayer (MATRIKS M, POINT Player);
// Mencari meja yang dekat dengan player
// Mengembalikan nomor meja yang berada di dekat player

POINT MejaDapurDekatPlayer (MATRIKS M, POINT Player);
// Mencari meja dapur yang dekat dengan player
// Mengembalikan posisi meja dapur di dekat player

#endif
