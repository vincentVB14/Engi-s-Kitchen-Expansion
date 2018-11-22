#include "modmesintree.h"

boolean EndTKata;
TKata TrKata;

void IgnoreBlankEnter()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  // KAMUS LOKAL

  // ALGORITMA
  while (((CC == BLANK2) || (CC == ENTER2)) && (CC != MARK))
  {
    ADV ();
  }
}

void SalinTree()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  // KAMUS LOKAL
  int i = 0;

  // ALGORITMA
  for (;;)
  {
    TrKata[i] = CC;
    ADV();
    if ((CC == MARK) || (CC == ENTER2) || (CC == CLOSEB) || (CC == OPENB) || (i >= NMaxT))
    {
      break;
    }
    else
    {
      i++;
    }
  }
  TrKata[i+1] = '\0';
}
