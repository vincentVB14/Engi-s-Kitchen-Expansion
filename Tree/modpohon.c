#include "modpohon.h"
#include "../Mesin/modmesinkar.c"
#include <stdlib.h>
#include <string.h>

/* *** Konstruktor *** */
BinTree Tree(infoTree Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (TNil) jika alokasi gagal */
{
  // KAMUS LOKAL
  addrNode P;

  // ALGORITMA
  P = AlokNode(Akar);
  if (P != TNil)
  {
    Left(P) = L;
    Right(P) = R;
  }
  return(P);
}
void MakeTree(infoTree Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = TNil jika alokasi gagal. */
{
  // KAMUS LOKAL

  // ALGORITMA
  *P = Tree(Akar,L,R);
}

void BuildTree (BinTree *P)
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
Memori pasti cukup, alokasi pasti berhasil. */
/* F.S. P dibentuk dari ekspresi dalam pita */
{
	ADV(); //karakter pertama sudah dibaca di driver dg START();
	if (CC == ')') {
		*P= TNil;
	} else {
		*P= Tree(CC, TNil, TNil);
		ADV();
		while (CC == ' ') ADV();
		BuildTree(&Left(*P));
		while (CC == ' ') ADV();
		BuildTree(&Right(*P));
		ADV();
	}
}


/* Manajemen Memory */
addrNode AlokNode(infoTree X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak TNil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = TNil, Right(P)=TNil */
/* Jika alokasi gagal, mengirimkan TNil */
{
  // KAMUS LOKAL
  addrNode P;

  // ALGORITMA
  P = (addrNode) malloc (sizeof(Node));
  if (P != TNil)
  {
    strcpy(X, Akar(P));
    Left(P) = TNil;
    Right(P) = TNil;
  }
  else
  {
    P = TNil;
  }
  return (P);
}
void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
  // KAMUS LOKAL

  // ALGORITMA
  free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
  // KAMUS LOKAL

  // ALGORITMA
  return (P == TNil);
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
  // KAMUS LOKAL

  // ALGORITMA
  if (!IsTreeEmpty(P))
  {
    return (Left(P) == TNil && Right(P) == TNil);
  }
  else
  {
    return false;
  }
}
boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
  // KAMUS LOKAL

  // ALGORITMA
  if (!IsTreeEmpty(P))
  {
    return (Left(P) != TNil && Right(P) == TNil);
  }
  else
  {
    return false;
  }
}
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
  // KAMUS LOKAL

  // ALGORITMA
  if (!IsTreeEmpty(P))
  {
    return (Left(P) == TNil && Right(P) != TNil);
  }
  else
  {
    return false;
  }
}
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
  // KAMUS LOKAL

  // ALGORITMA
  if (!IsTreeEmpty(P))
  {
    return (Left(P) != TNil && Right(P) != TNil);
  }
  else
  {
    return false;
  }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */

/*** Traversal ***/
void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
  // KAMUS LOKAL

  // ALGORITMA
  PrintTree2(P, h, 0);
}
void PrintTree2(BinTree P, int h, int count)
// Membantu prosedur printtree
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  if (!IsTreeEmpty(P))
  {
    for (i = 0; i < (h * count); i++)
    {
      printf(" ");
    }
    printf("%d\n", Akar(P));
    PrintTree2(Left(P), h, (count + 1));
    PrintTree2(Right(P), h, (count + 1));
  }
}
