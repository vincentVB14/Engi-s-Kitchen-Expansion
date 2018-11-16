/* File: game_mechanic.h */
/* File header yang berisi fungsi/prosedur untuk game mechanic yang membutuhkan
gabungan dari beberapa ADT */

#include "kamus.h"

void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep);
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack terdefinisi, Tree terdefinisi */
/* F.s. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */

void AddOrder (MATRIKS M, POINT P, TabInt *O)
/* Menerima pesanan customer */
void DelOrder (POINT P, TabInt *O)
/* Menerima pesanan customer */
