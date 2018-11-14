// BODY dari ADT GRAPH

#include <stdio.h>
#include "graph.h"

// KONSTRUKTOR
void CreateGraph (int N, MATRIKS * G)
/* Membentuk sebuah GRAPH "kosong" yang siap diisi berukuran NxN di "ujung kiri" memori */
/* I.S. N adalah valid untuk memori matriks yang dibuat */
/* F.S. Graph G sesuai dengan definisi di atas terbentuk */
{
  // KAMUS lOKAL

  // ALGORITMA
  GVertex (*G) = N;
}

// Perintah-perintah lain
boolean IsIdxValidGraph (int N)
/* Mengirimkan true jika v adalah indeks yang valid untuk graph apa pun */
{
  // KAMUS lOKAL

  // ALGORITMA
  return (N >= VertexMin && N <= VertexMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxGraph (Graph G)
/* Mengirimkan indeks baris terkecil G */
{
  // KAMUS lOKAL

  // ALGORITMA
  return (VertexMin);
}
indeks GetLastIdxGraph (Graph G)
/* Mengirimkan indeks baris terbesar G */
{
  // KAMUS lOKAL

  // ALGORITMA
  return (VertexMin + GVertex(G) - 1);
}
boolean IsIdxEffGraph (Graph G, Gindeks i, Gindeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi graph G */
{
  // KAMUS lOKAL

  // ALGORITMA
  return (i >= GetFirstIdxGraph (G) && i <= GetLastIdxGraph (G) &&
          j >= GetFirstIdxGraph (G) && j <= GetLastIdxGraph (G));
}

// Predikat Graph
boolean AdjacentGraph (Graph G, Vertex v1, Vertex v2)
// Membuktikan bahwa posisi dari ruangan adalah bertetangga
{
  // KAMUS lOKAL

  // ALGORITMA
  return (GElmt(G,))
}

// Operasi dalam Graph
void AddV (Graph G, Vertex v)
// Menambahkan satu buah vertex terhadap graph
{
  // KAMUS lOKAL

  // ALGORITMA
}
void DeleteV (Graph G, Vertex v)
// Menghapus satu buah vertex terhadap graph
{
  // KAMUS lOKAL

  // ALGORITMA
}
void AddE (Graph G, Vertex v1, Vertex v2)
// Menambahkan edge dari vertex 1 ke vertex 2
{
  // KAMUS lOKAL

  // ALGORITMA
}
void DeleteE (GraphG, Vertex v1, Vertex v2)
// Menghapus edge antara 1 vertex dengan vertex 2
{
  // KAMUS lOKAL

  // ALGORITMA
}
