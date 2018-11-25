/* Body ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi I dengan Priority Queue (Orang dengan kesabaran lebih rendah diutamakan) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modqueue.h"

/* Definisi Queue kosong: HEAD=NilQueue; TAIL=NilQueue. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
/* KAMUS LOKAL */
     /* Tidak menggunakan kamus lokal */
/* ALGORITMA */
     return ((Head(Q) == NilQueue) && (Tail(Q) == NilQueue));
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
          return NilQueue;
     else {
          position = Head(Q);
          count = 1;
          while (position != Tail(Q)){
               count++;
               position++;
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
          Head(*Q) = NilQueue;
          Tail(*Q) = NilQueue;
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
     if (NBElmtQueue(*Q) == MaxEl(*Q)){
          printf("Antrian penuh.\n");
     }
     else {
          srand(time(NULL));
          // rand() % (max_number + 1 - minimum_number) + minimum_number
          InfoJumlah(X) = rand() % (4 + 1 - 1) + 1;
          if (InfoJumlah(X) == 1){
               InfoJumlah(X)++;
          }
          else if (InfoJumlah(X) == 3){
               InfoJumlah(X)++;
          }
          InfoSabar(X) = 30;
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
}

void DelQueue2(Queue * Q, customer * X){
/* Proses: Menghapus X yang memiliki jumlah orang = 2 pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen yang memiliki jumlah orang = 2 pd I.S., Geser;
        Q mungkin kosong */
// KAMUS LOKAL
     // Tidak menggunakan kamus lokal
// ALGORITMA
     InfoJumlah(*X) = NilQueue;
     InfoSabar(*X) = NilQueue;
     if (IsEmptyQueue(*Q)){
          printf("Antrian kosong.\n");
          InfoJumlah(*X) = NilQueue;
          InfoSabar(*X) = NilQueue;
     }
     else {
          if (Head(*Q) == Tail(*Q) && InfoJumlah(ElmtQueue(*Q,Head(*Q))) == 2){
               *X = InfoHead(*Q);
               Head(*Q) = NilQueue;
               Tail(*Q) = NilQueue;
          }
          else {
               int i = Head(*Q);
               while (i < Tail(*Q) && InfoJumlah(ElmtQueue(*Q,i)) != 2){
                    i++;
               }
               if (InfoJumlah(ElmtQueue(*Q,i)) == 2){
                    *X = ElmtQueue(*Q,i);
                    while (i < Tail(*Q)){
                         ElmtQueue(*Q,i) = ElmtQueue(*Q,i+1);
                         i++;
                    }
                    Tail(*Q) = i-1;
               }
          }
     }
}

void DelQueue4(Queue * Q, customer * X){
/* Proses: Menghapus X yang memiliki jumlah orang = 4 pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju";
        Q mungkin kosong */
// KAMUS LOKAL
     // Tidak menggunakan kamus lokal
// ALGORITMA
     InfoJumlah(*X) = NilQueue;
     InfoSabar(*X) = NilQueue;
     if (IsEmptyQueue(*Q)){
          printf("Antrian kosong.\n");
          InfoJumlah(*X) = NilQueue;
          InfoSabar(*X) = NilQueue;
     }
     else {
          if (Head(*Q) == Tail(*Q) && InfoJumlah(ElmtQueue(*Q,Head(*Q))) == 4){
               *X = InfoHead(*Q);
               Head(*Q) = NilQueue;
               Tail(*Q) = NilQueue;
          }
          else {
               int i = Head(*Q);
               while (i < Tail(*Q) && InfoJumlah(ElmtQueue(*Q,i)) != 4){
                    i++;
               }
               if (InfoJumlah(ElmtQueue(*Q,i)) == 4){
                    *X = ElmtQueue(*Q,i);
                    while (i < Tail(*Q)){
                         ElmtQueue(*Q,i) = ElmtQueue(*Q,i+1);
                         i++;
                    }
                    Tail(*Q) = i-1;
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
     if (IsEmptyQueue(*Q)){
          printf("Antrian kosong.\n");
          InfoJumlah(*X) = NilQueue;
          InfoSabar(*X) = NilQueue;
     }
     else {
          *X = InfoHead(*Q);
          if (Head(*Q) == Tail(*Q)){
               Head(*Q) = NilQueue;
               Tail(*Q) = NilQueue;
          }
          else {
               int i = Head(*Q);
               while (i < Tail(*Q)){
                    ElmtQueue(*Q,i) = ElmtQueue(*Q,i+1);
                    i++;
               }
               Tail(*Q) = i-1;
          }
     }
}

void KurangSabarQueue(Queue * Q, int * Life){
/* I.S. Q terdefinisi, mengurangi kesabaran sebanyak 1 satuan
   F.S. Kesabaran customer berkurang satu
*/
/* KAMUS LOKAL */
     customer X;
/* ALGORITMA */
     if (IsEmptyQueue(*Q)){
          // do nothing
     }
     else {
          int i = Head(*Q);
          while(i <= Tail(*Q)){
               InfoSabar(ElmtQueue(*Q,i))--;
               i++;
          }
          while (InfoSabarHead(*Q) == 0 && !IsEmptyQueue(*Q)){
               DelQueue(Q,&X);
               *Life = *Life - 1;
          }
     }
}

void UpdateQueue (Queue *Q){
// mengassign nilai Tabel Queue dengan indeks > Tail dengan nilai -1
  int i;
  for (i = Tail(*Q) + 1;i <= MaxEl(*Q);i++){
    InfoJumlah(ElmtQueue(*Q,i)) = NilQueue;
    InfoSabar(ElmtQueue(*Q,i)) = NilQueue;
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
          int i = Head(Q);
          printf("(%d,%d)",Q.T[i].jumlahorang,Q.T[i].kesabaran);
          while (i != Tail(Q)){
               i++;
               printf(",(%d,%d)",Q.T[i].jumlahorang,Q.T[i].kesabaran);
          }
          // for (int i = Head(Q)+1; i <= Tail(Q); i++){
          //      printf(",(%d,%d)",Q.T[i].jumlahorang,Q.T[i].kesabaran);
          // }
          printf("]");
     }
}
