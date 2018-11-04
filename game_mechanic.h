/* File: game_mechanic.h */
/* File header yang berisi fungsi/prosedur untuk game mechanic yang membutuhkan
gabungan dari beberapa ADT */

#include "kamus.h"

void TakeFood(Stack * Hand);
/*Prosedur untuk mengambil makanan dan menambahkannya ke Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak penuh*/
/*F.S. Top dari Stack Hand berupa makanan di samping player*/

void EmptyHand(Stack * Hand);
/*Prosedur untuk mengosongkan Stack Hand*/
/*I.S. Stack Hand terdefinisi, tidak kosong*/
/*F.S. Stack Hand kosong*/

void EmptyTray(Stack * Tray);
/*Prosedur untuk mengosongkan Stack Tray*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Stack Tray kosong*/

void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep);
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi*/
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */

void GiveFood(Stack * Tray);
/*Prosedur untuk memberikan makan paling atas tumpukan*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Makanan paling atas di Stack Tray di-Pop*/
