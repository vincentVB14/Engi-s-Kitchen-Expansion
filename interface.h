/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: interface.h */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Interface */

#ifndef interface_H
#define interface_H

#include "kamus.h"

/* ********** Tampilan Menu ********** */
void MainMenu ();
/* Prosedur untuk tampilan menu sebelum permainan dimulai */

/* ********** Tampilan Permainan ********** */
void Room (Gaddress P);
/* Prosedur untuk tampilan ruangan saat permainan berlangsung */
void Info (Queue Q, TabInt T, TabInt O, TabInt H);
/* Prosedur untuk tampilan informasi saat permainan berlangsung */
void Play (char *name, int money, int life, int time, Gaddress P);
/* Prosedur untuk tampilan saat permainan berlangsung */

/* ********** Tampilan Setelah Permainan Berakhir ********** */
//void GameOver (Stat s);
/* Prosedur untuk tampilan game over */
//void Credit (Stat s);
/* Prosedur untuk tampilan credit */

/* ********** Tampilan Lain ********** */
void Legend ();
/* Prosedur untuk tampilan legenda */
#endif
