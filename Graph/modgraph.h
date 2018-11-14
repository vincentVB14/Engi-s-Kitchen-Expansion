// HEADER dari ADT GRAPH
// Representasi Graph menggunakan matriks

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "../Point/modpoint.h"
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
  Gaddress2 FirstChild;
} Ruangan;
typedef struct tElmtGraph2 {
  Ginfotype2 info2G;
  Gaddress2 NextChild;
} NextRuangan;

typedef struct {
	address FirstG;
} Graph;


// SELEKTOR
#define Nomor(P) (P)->infoG.nomor
#define Ruangan(P) (P)->infoG.ruangan
#define NextP(P) (P)->NextParent
#define FirstChild(P) (P)->FirstChild
#define NomorTarget(P2) (P2)->info2G.nomortarget
#define PrevLoc(P2) (P2)->info2G.prevloc
#define NextLoc(P2) (P2)->info2G.nextloc
#define NextChild(P2) (P2)->NextChild
#define FirstG(L) (L).FirstG

// KONSTRUKTOR
void CreateEmptyGraph (Graph *G);
// Menciptakan graph kosong yang dapat digunakan
// Keterangan, first dari graph adalah Nil
boolean IsEmptyGraph (Graph *G);
// Mengirim true jika draf kosong

/****************** Manajemen Memori ******************/
address AlokasiGraph1 (Ginfotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address AlokasiGraph2 (Ginfotype2 X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN GRAOH ******************/
address Search (Graph L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan GNil */

/* PENAMBAHAN DAN PENGHAPUSAN ELEMEN GRAPH */
void AddRuangan (Graph *G, Ginfotype X);
/* Menambahkan ruangan ke dalam graf */
// Melakukan AddLast
void DelRuangan (Graph *G, Ginfotype *X);
/* Menghapus ruangan dari dalam graf */
// Melakukan DelLast
void AddNextRuangan (Graph *G, Ginfotype2 X);
/* Menambahkan anak dari ruangan di graf yang berisi info ke next ruangan */
// Melakukan AddLast
void DelNextRuangan (Graph *G, Ginfotype2 X);
/* Menambahkan anak dari ruangan di graf yang berisi info ke next ruangan */
// Melakukan DelLast

int NextRuangan (Graph *G, int currRuangan) // Masih dipikirkan

#endif
