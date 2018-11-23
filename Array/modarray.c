/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: modarray.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Kamus */

#include "modarray.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void CreateEmptyArray (TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	//KAMUS LOKAL

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

void BacaIsi (TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
	//Kamus
	IdxType i;
	boolean found;
	int isi;
	char food[20];
	int kesabaran;

	//Algoritma
	i = GetFirstIdx(*T);
	found = false;
	MakeEmpty(T);
	while ((found == false) && (NbElmt(*T) < MaxNbEl(*T)))
	{
		scanf ("%d", &isi);
		scanf ("%s", &food);
		scanf ("%d", &kesabaran);
		if (isi == -9999)
		{
			found = true;
		}
		else
		{
			No(*T,i) = isi;
			Food(*T,i) = food;
			Kesabaran(*T,i) = kesabaran;
			Neff(*T) += 1;
			i++;
		}
	}
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50 */
{
	//Kamus
	IdxType i;

	//Algoritma
	if (IsEmpty(T) == true)
	{
		printf ("Tabel kosong\n");
	}
	else
	{
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			printf("[%d] %-15d. %-15s %-15d\n", i, No(T,i), Food(T,i), Kesabaran(T,i));
		}
	}
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
