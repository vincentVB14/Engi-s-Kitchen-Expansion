/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINTREE_H__
#define __MESINTREE_H__

#include "boolean.h"
#include "modmesinkar.h"

#define NMaxT 20
#define BLANK2 ' '
#define ENTER2 '\n'
#define CLOSEB ')'
#define OPENB '('

typedef char TKata[NMaxT+1];

/* State Mesin Kata */
extern boolean EndTKata;
extern TKata TrKata;

void IgnoreBlankEnter();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void SalinTree();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif
