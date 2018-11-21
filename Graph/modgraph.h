// HEADER dari ADT GRAPH
// Representasi Graph menggunakan matriks

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "../Matriks/modmatriks.h"

#define GNil NULL
#define GNil2 -1
#define VertexMin 1
#define VertexMax 4

typedef struct tElmtGraph *Gaddress;
typedef struct tElmtGraph2 *Gaddress2;

typedef struct {
  int nomor;
  MATRIKS ruangan;
} Ginfotype;
typedef struct {
  int nomortarget;
  POINT prevloc;
  POINT nextloc;
} Ginfotype2;

typedef struct tElmtGraph {
  Ginfotype infoG;
  Gaddress NextParent;
  Gaddress2 Firstchild;
} Ruangan;
typedef struct tElmtGraph2 {
  Ginfotype2 info2G;
  Gaddress2 Nextchild;
} NextRuangan;

typedef struct {
	Gaddress GFirst;
  int currRoom;
} Graph;


// SELEKTOR
#define Nomor(P) (P)->infoG.nomor
#define Ruangann(P) (P)->infoG.ruangan
#define NextP(P) (P)->NextParent
#define FirstChild(P) (P)->Firstchild
#define NomorTarget(P2) (P2)->info2G.nomortarget
#define PrevLoc(P2) (P2)->info2G.prevloc
#define NextLoc(P2) (P2)->info2G.nextloc
#define NextChild(P2) (P2)->Nextchild
#define FirstG(L) (L).GFirst
#define CurrentRoom(L) (L).currRoom

// KONSTRUKTOR
void CreateEmptyGraph (Graph *G);
// Menciptakan graph kosong yang dapat digunakan
// Keterangan, first dari graph adalah Nil
boolean IsEmptyGraph (Graph G);
// Mengirim true jika draf kosong
boolean IsEmptyParent (Gaddress P);
// Mengirim true jika P adalah kosong

/****************** Manajemen Memori ******************/
Gaddress AlokasiGraph1 (int no, char *filename);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
Gaddress2 AlokasiGraph2 (int no, POINT Prev, POINT Next);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiGraph1 (Gaddress *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void DealokasiGraph2 (Gaddress2 *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN GRAPH ******************/
Gaddress SearchRuangan (Graph G, int X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan GNil */

Gaddress2 SearchNextRuangan (Gaddress CurrP, POINT Player);
// Mencari apakah Player bisa pindah ke ruangan lain
// Jika dapat mengembalikan NextRuangan
// Jika tidak, mengembalikan GNil

/* PENAMBAHAN DAN PENGHAPUSAN ELEMEN GRAPH */
void AddRuangan (Graph *G, int no, char *filename);
/* Menambahkan ruangan ke dalam graf */
// Melakukan AddLast
void AddNextRuangan (Gaddress *P, int no, POINT Prev, POINT Next);
/* Menambahkan anak dari ruangan di graf yang berisi info ke next ruangan */
// Melakukan AddLast

/* PEMBACAAN FILE KE MATRIKS DAN GRAPH */
void FileToMatriks (Gaddress *P, char * filename);
/* Mengkopi semua isi file ke dalam matriks agar
   dapat diperlakukan sebagai matriks peta */

void FileToMatriksDapur(Gaddress *P, char * filename);
/* Mengkopi semua isi file ke dalam matriks dapur agar
  dapat diperlakukan sebagai matriks peta */


/* PEMBACAAN RUANGAN */
void BacaPeta (Graph *G, POINT *Player);
// Prosedur membaca peta dari file eksternal

void PindahRuangan (Graph *G, Gaddress *P, POINT *Player, boolean *valid);
// Memindahkan player dari suatu ruangan ke ruangan lainnya

void ReduceKesabaranG (Graph *G, int *life);
// Mengurangi kesabaran seluruh MAP

#endif
