// Nama / NIM : Ferdy Santoso / 13517116
// Tanggal : 1 Oktober 2018
/* File : queue.c */
/* Body ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modqueue.h"

/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFullQueue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     return (NBElmtQueue(Q) == MaxEl(Q));

}

int NBElmtQueue (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
/* KAMUS LOKAL */
     int count;
     address position;

/* ALGORITMA */
     if (IsEmptyQueue(Q))
          return Nil;
     else {
          position = Head(Q);
          count = 1;
          while (position != Tail(Q)){
               count++;
               if (position != MaxEl(Q)){
                    position++;
               }
               else{
                    position = 1;
               }
          }
          return count;
     }
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     (*Q).T = (customer *) malloc ((Max+1) * sizeof(customer));
     if ((*Q).T != NULL) {
          MaxEl(*Q) = Max;
          Head(*Q) = Nil;
          Tail(*Q) = Nil;
     } else /* alokasi gagal */ {
          MaxEl(*Q) = 0;
     }
}

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     MaxEl(*Q) = 0;
     free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
/* KAMUS LOKAL */
// KAMUS LOKAL
     customer temp,X;
     address i,j;

// ALGORITMA
     srand(time(NULL));
     // rand() % (max_number + 1 - minimum_number) + minimum_number
     InfoJumlah(X) = rand() % (4 + 1 - 1) + 1;
     InfoSabar(X) = rand() % (60 + 1 - 30) + 30;
     if (IsEmptyQueue(*Q))
     {
      Head(*Q) = 1;
      Tail(*Q) = 1;
      InfoTail(*Q) = X;
     }
     else
     {
      if (Tail(*Q) == MaxEl(*Q))
      {
         Tail(*Q) = 1;
      }
      else
      {
         Tail(*Q)++;
      }
      InfoTail(*Q) = X;

      i = Tail(*Q);
      if (i == 1)
      {
         j = MaxEl(*Q);
      }
      else
      {
         j = i - 1;
      }

      while (InfoSabar(ElmtQueue(*Q,i)) < InfoSabar(ElmtQueue(*Q,j)) && (i != Head(*Q)))
      {
         temp = ElmtQueue(*Q,i);
         ElmtQueue(*Q,i) = ElmtQueue(*Q,j);
         ElmtQueue(*Q,j) = temp;

         i--;j--;
         if (i < 1)
         {
           i = MaxEl(*Q);
         }
         if (j < 1)
         {
           j = MaxEl(*Q);
         }
      }
     }
}

void DelQueue (Queue * Q, customer * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     *X = InfoHead(*Q);
     if (Head(*Q) == Tail(*Q)){
          Head(*Q) = Nil;
          Tail(*Q) = Nil;
     }
     else {
          if (Head(*Q) == MaxEl(*Q)){
               Head(*Q) = 1;
          }
          else{
               Head(*Q)++;
          }
     }
}

void PrintQueue (Queue Q){
/* I.S. Q terdefinisi, Q mungkin kosong
   F.S. Isi Queue ditampilkan ke layar,
   Format output : "[e1,e2,...,eN]"
   NB : tampilkan "[]" jika Queue kosong */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     if (IsEmptyQueue(Q)){
          printf("[]");
     }
     else {
          printf("[");
          printf("(%d,%d)",InfoJumlahHead(Q),InfoSabarHead(Q));
          for (int i = Head(Q)+1; i <= Tail(Q); i++){
               printf(",(%d,%d)",Q.T[i].jumlahorang,Q.T[i].kesabaran);
          }
          printf("]");
     }
}
