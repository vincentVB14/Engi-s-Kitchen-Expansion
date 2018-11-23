/* File: game_mechanic.h */
/* File header yang berisi fungsi/prosedur untuk game mechanic yang membutuhkan
gabungan dari beberapa ADT */

#include "kamus.h"

void NewGame();
/*Prosedur untuk menginput nama player*/
/*I.S. Player belum memiliki nama*/
/*F.S. Player memiliki nama dan memanggil StartGame()*/

void StartGame();
/*Prosedur untuk memulai permainan*/
/*I.S. Mengecek apakah player sudah memiliki nama. Jika belum, memanggil NewGame(). Jika sudah, memulai permainan*/
/*F.S. Game selesai dengan life player == 0, kemudian menampilkan Credit()*/

void LoadGame();
/*Prosedur untuk load permainan dari file eksternal*/
/*I.S. Permainan belum dimulai*/
/*F.S. Permainan dimulai dengan kondisi yang sesuai dengan hasil simpanan di file eksternal*/

void EveryTurn (Graph *G, int *Life, int *Time, Queue*Q);
// Melakukan apa yang dilakukan pada setiap turn
// Mengurangi kesabaran setiap orang di meja
// Menambahkan waktu
// Mengeluarkan setiap pelanggan yang kesabarannya mencapai 0
// Megurangi kesabaran setiap pelanggan yang menunggu di Queue

void TakeFood(Stack * Hand, MATRIKS room, POINT Player);
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

//void CreateFood(Stack * Hand, Stack * Tray,  Bintree Resep);
/* Prosedur untuk Pop semua isi Stack Hand, membandingkan dengan tree, dan
kemudian membuat makanan dengan Push ke Stack Tray*/
/* I.S. Stack Hand terdefinisi, Bintree Resep terdefinisi*/
/* F.S. Stack Tray terisi dengan daun makanan dari Tree, Stack Hand kosong */

void GiveFood(Stack * Tray);
/*Prosedur untuk memberikan makan paling atas tumpukan*/
/*I.S. Stack Tray terdefinisi, tidak kosong*/
/*F.S. Makanan paling atas di Stack Tray di-Pop*/

void AddOrder (MATRIKS *M, POINT P, TabInt *O);
/* Menerima pesanan customer */

void DelOrder (POINT P, TabInt *O);
/* Menerima pesanan customer */
