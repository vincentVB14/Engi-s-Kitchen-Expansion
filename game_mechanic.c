/* File: game_mechanic.c */
/* File ini berisi implementasi dari game_mechanic.h */

#include "kamus.h"

void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep)
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi, isi Hand terurut
berdasarkan Bintree Resep */
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */
{
  Push(Tray, Akar(P));
}

void AddOrder (MATRIKS M, POINT P, TabInt *O)
/* Menerima pesanan customer */
{
	//Kamus
	int i;
	
	//Algoritma
	if (IsFull(*O))
	{
		printf("Tidak dapat menerima pesanan\n");
	}
	else
	{
		i = GetLastIdx(*O) + 1;
		strcpy(No(*O,i), MElmt3(*M,Absis(P),Ordinate(P)));
		Food(*O,i) = ;
		Kesabaran(*O,i) = MElmt5(*M,Absis(P),Ordinate(P));
		Neff(*O)++;
	}
}

void DelOrder (POINT P, TabInt *O)
/* Menerima pesanan customer */
{
	//Kamus
	ElType temp;
	int i;
	
	//Algoritma
	i = GetFirstIdx(*O);
	if (Kesabaran(*O,i) == 0)
	{
		DelEli(O, i, &temp);
	}
}
