/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: modarray.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Kamus */

#include "modarray.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	//KAMUS LOKAL
	int i;

	//ALGORITMA
	Neff(*T) = 0;
}

IdxType GetFirstIdxArray (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (IdxMin);
}
IdxType GetLastIdxArray (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T) == 0);
}
boolean IsFullArray (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	//KAMUS LOKAL

	//ALGORITMA
	return (Neff(T) == IdxMax);
}

void DelEli (TabInt *T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//Kamus
	IdxType j;
 	//Algoritma
	*X = Elmt(*T, i);
	if (IsEmptyArray(*T) == false)
	{
		for(j = i; j < GetLastIdxArray(*T); j++)
		{
			Elmt(*T, j) = Elmt(*T, (j + 1));
		}
		Neff(*T) -= 1;
	}
}
