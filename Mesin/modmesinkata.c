 #include "modmesinkata.h"

 boolean EndKata;
 boolean NewLine;
 Kata CKata;

 void IgnoreBlank()
 /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC ≠ BLANK atau CC = MARK */
 {
   // KAMUS LOKAL

   // ALGORITMA
   while ((CC == BLANK) && (CC != MARK))
   {
     ADV ();
   }
 }

 void STARTKATA(char * filename)
 /* I.S. : CC sembarang
    F.S. : EndKata = true, dan CC = MARK;
           atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
           CC karakter pertama sesudah karakter terakhir kata */
 {
   // KAMUS LOKAL

   // ALGORITMA
   START (filename);
   IgnoreBlank ();
   if (CC == MARK)
   {
     EndKata = true;
   }
   else if (CC == ENTER)
   {
     EndKata = false;
     NewLine = true;
   }
   else
   {
     EndKata = false;
     NewLine = false;
     SalinKata ();
   }
 }

 void ADVKATA()
 /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
    F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
           CC adalah karakter pertama dari kata berikutnya, mungkin MARK
           Jika CC = MARK, EndKata = true.
    Proses : Akuisisi kata menggunakan procedure SalinKata */
 {
   // KAMUS LOKAL

   // ALGORITMA
   if (NewLine)
   {
     ADV();
     NewLine = false;
   }
   IgnoreBlank ();
   if (CC == MARK)
   {
     EndKata = true;
   }
   else if (CC == ENTER)
   {
     NewLine = true;
   }
   else
   {
     SalinKata ();
   }
 }

 void SalinKata()
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
     CKata[i] = CC;
     ADV();
     if ((CC == MARK) || (CC == ENTER) || (CC == BLANK) || (i >= NMax))
     {
       break;
     }
     else
     {
       i++;
     }
   }
   CKata[i+1] = '\0';
 }
