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
