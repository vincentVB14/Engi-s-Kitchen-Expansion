/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: modarray.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Kamus */

/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef MODARRAY_H
#define MODARRAY_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxMax 5
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct {
	int No;
	char Food[20];
	int Kesabaran;
} ElType;   /* type elemen tabel */
typedef struct {
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]
#define No(T,i)		(T).TI[(i)].No
#define Food(T,i)	(T).TI[(i)].Food
#define Kesabaran(T,i)	(T).TI[(i)].Kesabaran

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void CreateEmptyArray (TabInt *T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArray (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdxArray (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArray (TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void DelEli (TabInt *T, IdxType i, ElType * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

#endif
