/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: interface.c */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Realisasi Modul Interface */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "interface.h"

/* ********** Tampilan Menu ********** */
void MainMenu ()
/* Prosedur untuk tampilan menu sebelum permainan dimulai */
{
	//Kamus
	int i, j, k;
	char t1[90] = "|            _        _____  _______  _____   _    _  _  __ _____         _______  |";
	char t2[90] = "|     /\\    | |      / ____||__   __||  __ \\ | |  | || |/ /|  __ \\    /\\ |__   __| |";
	char t3[90] = "|    /  \\   | |     | (___     | |   | |__) || |  | || ' / | |  | |  /  \\   | |    |";
	char t4[90] = "|   / /\\ \\  | |      \\___ \\    | |   |  _  / | |  | ||  <  | |  | | / /\\ \\  | |    |";
	char t5[90] = "|  / ____ \\ | |____  ____) |   | |   | | \\ \\ | |__| || . \\ | |__| // ____ \\ | |    |";
	char t6[90] = "| /_/    \\_\\|______||_____/    |_|   |_|  \\_\\ \\____/ |_|\\_\\|_____//_/    \\_\\|_|    |";

	//Algoritma
	for(i = 0; i < 4; i++)
	{
		printf("|----------------------------------------------------------------------------------|\n");
		switch (i)
		{
			case 1 :
			{
				printf("%s\n",t1);
				printf("%s\n",t2);
				break;
			}
			case 2 :
			{
				printf("%s\n",t1);
				printf("%s\n",t2);
				printf("%s\n",t3);
				printf("%s\n",t4);
				break;
			}
			case 3 :
			{
				printf("%s\n",t1);
				printf("%s\n",t2);
				printf("%s\n",t3);
				printf("%s\n",t4);
				printf("%s\n",t5);
				printf("%s\n",t6);
				break;
			}
		}
		for(j = (7 - (i*2)); j > 0; j--)
		{
			printf("|                                                                                  |\n");
		}
		printf("|----------------------------------------------------------------------------------|\n");
		if(i != 3)
		{
			sleep(1);
			system("cls");
		}
		else
		{
			sleep(1);
		}
	}
	for(k = 1; k <= 3; k++)
	{
		system("cls");
		sleep(1);
		printf("|----------------------------------------------------------------------------------|\n");
		printf("%s\n",t1);
		printf("%s\n",t2);
		printf("%s\n",t3);
		printf("%s\n",t4);
		printf("%s\n",t5);
		printf("%s\n",t6);
		printf("|                                                                                  |\n");
		printf("|----------------------------------------------------------------------------------|\n");
		sleep(1);
	}
	sleep(1);
	system("cls");
	printf("|----------------------------------------------------------------------------------|\n");
	printf("|                                  Engi's Kitchen                                  |\n");
	printf("|----------------------------------------------------------------------------------|\n");
	printf("|         ____________                                                             |\n");
	printf("|        /////////////\\                                                            |\n");
	printf("|       /////////////__\\                                Main Menu :                |\n");
	printf("|       |   ENGI'S  |  |                                1. New Game                |\n");
	printf("|       |     _     |  |                                2. Start Game              |\n");
	printf("|       | [] | | [] |[]|                                3. Load Game               |\n");
	printf("|       |    | |    |  |                                4. Exit                    |\n");
	printf("|       `````) )`````                                                              |\n");
	printf("|----------------------------------------------------------------------------------|\n");
}

/* ********** Tampilan Permainan ********** */
void Room (Gaddress P, Graph G)
/* Prosedur untuk tampilan ruangan saat permainan berlangsung */
{
	//Kamus
	indeks i, j;

	//Algoritma
	for (i = GetFirstIdxBrsMatrix(Ruangann(P)); i <= GetLastIdxBrsMatrix(Ruangann(P)); i++)
	{
		printf("| ********************** | ");
		for (j = GetFirstIdxKolMatrix(Ruangann(P)); j <= GetLastIdxKolMatrix(Ruangann(P)); j++)
		{
			switch(MElmt(Ruangann(P),i,j))
			{
				case ('P'):     // Player
				{
					printf("P ");
					break;
				}
				case ('L'):     // Lantai
				{
					printf("  ");
					break;
				}
				case ('X'):    // Kursi
				{
					if (MElmt2(Ruangann(P),i,j))
					{
						printf("C ");
					}
					else
					{
						printf("X ");
					}
					break;
				}
				case ('M'):       // Meja Customer
				{
					if(CurrentRoom(G) == 4)
					{
						printf("M ");
					}
					else
					{
						printf("%-2s", MElmt3(Ruangann(P),i,j));
					}
					break;
				}
				case ('T'):
				{
					printf("T ");
					break;
				}
			}
			if (j != GetLastIdxKolMatrix(Ruangann(P)))
			{
				printf(" | ");
			}
			else if (i <= GetLastIdxBrsMatrix(Ruangann(P)))
			{
				printf(" | *********************** |\n");
				printf("|------------------------------------------------------------------------------------------|\n");
			}
		}
	}
}

void Info (Queue Q, Stack T, TabInt O, Stack H)
/* Prosedur untuk tampilan informasi Stack permainan berlangsung */
{
	//Kamus
	int i;
	infostack X;
	infostack Y;
	Queue Qtemp;
	Stack Htemp;
	Stack Ttemp;

	//Algoritma
	printf("| Hand :                                    |  Food Tray:                                  |\n");
	CopyStack(H, &Htemp);
	CopyStack(T, &Ttemp);
	UpdateQueue(&Q);
	i = 1;
	do
	{
		if(!IsEmptyStack(Htemp)){
			Pop(&Htemp, &X);
		} else{
			X = "";
		}
		if(!IsEmptyStack(Ttemp)){
			Pop(&Ttemp, &Y);
		} else{
			Y = "";
		}
		printf("| %d. %-38s |  %d. %-38s   |\n", i, X, i, Y);
		i++;
	} while (i != 6);
	printf("|------------------------------------------------------------------------------------------|\n");
	printf("| Order :                                   | Waiting Customer:                            |\n");

	i = 1;
	do{
		printf("| %d. ", i);
		if(No(O,i) != -1){
			printf("Meja no. %-2d-", No(O,i));
		} else{
			printf("            ");
		}
		if(FakeStrCmp(Food(O,i), "") != 0){
			printf(" %-19s ", Food(O,i));
		} else{
			printf("                     ");
		}
		if(Kesabaran(O, i) != -1){
			printf(" [%2d]", Kesabaran(O, i));
		} else{
			printf("     ");
		}
		printf(" | ");
		printf(" %d. ", i);
		if(Q.T[i].jumlahorang != -1){
			printf("%d - ", Q.T[i].jumlahorang);
		} else{
			printf("  ");
		}
		if(Q.T[i].kesabaran != -1){
			printf("[%2d]                                 |\n",Q.T[i].kesabaran);
		} else{
			printf("                                       |\n");
		}
		i++;
	} while(i < IdxMax + 1);
}


void Play (char *name, int money, int life, int time, Gaddress P, Graph G, Queue Q, Stack T, TabInt O, Stack H, POINT player)
/* Prosedur untuk tampilan saat permainan berlangsung */
{
	//Kamus

	//Algoritma

		printf(" __________________________________________________________________________________________ \n");
		printf("| %-15s | Money: %-15d | Life: %-15d | Time: %-15d |\n", name, money, life, time);
		printf("|------------------------------------------------------------------------------------------|\n");
		if(CurrentRoom(G) == 4)
		{
			printf("|                                        Dapur                                             |\n");
		}
		else
		{
			printf("|                                      Ruangan  %d                                          |\n", Nomor(P));
		}
		printf("|------------------------------------------------------------------------------------------|\n");
		Room(P, G);
		if(CurrentRoom(G) == 4){
			POINT meja = MejaDapurDekatPlayer(Ruangann(P), player);
			if(Absis(meja) != 0 && Ordinat(meja) != 0){
				printf("| Info meja dapur = %-38s                                 |\n", MElmt3(Ruangann(P), Absis(meja), Ordinat(meja)));
			} else{
				printf("| Info meja dapur =                                                                        |\n");
			}
		}
		printf("|------------------------------------------------------------------------------------------|\n");
		Info(Q,T,O,H);
		printf("|__________________________________________________________________________________________|\n");
}

/* ********** Tampilan Setelah Permainan Berakhir ********** */
void GameOver (char *name, int money, int time)
/* Prosedur untuk tampilan game over */
{
	//Kamus
	int i, j;
	char t1[80] = "|   _____            __  __  ______    ____ __      __ ______  _____   |";
	char t2[80] = "|  / ____|    /\\    |  \\/  ||  ____|  / __ \\\\ \\    / /|  ____||  __ \\  |";
	char t3[80] = "| | |  __    /  \\   | \\  / || |__    | |  | |\\ \\  / / | |__   | |__) | |";
	char t4[80] = "| | | |_ |  / /\\ \\  | |\\/| ||  __|   | |  | | \\ \\/ /  |  __|  |  _  /  |";
	char t5[80] = "| | |__| | / ____ \\ | |  | || |____  | |__| |  \\  /   | |____ | | \\ \\  |";
	char t6[80] = "|  \\_____//_/    \\_\\|_|  |_||______|  \\____/    \\/    |______||_|  \\_\\ |";

	//Algoritma
	do
	{
		for(i = 0; i < 7; i++)
		{
			printf(" ______________________________________________________________________ \n");
			switch (i)
			{
				case 1 :
				{
					printf("%s\n",t1);
					break;
				}
				case 2 :
				{
					printf("%s\n",t1);
					printf("%s\n",t2);
					break;
				}
				case 3 :
				{
					printf("%s\n",t1);
					printf("%s\n",t2);
					printf("%s\n",t3);
					break;
				}
				case 4 :
				{
					printf("%s\n",t1);
					printf("%s\n",t2);
					printf("%s\n",t3);
					printf("%s\n",t4);
					break;
				}
				case 5 :
				{
					printf("%s\n",t1);
					printf("%s\n",t2);
					printf("%s\n",t3);
					printf("%s\n",t4);
					printf("%s\n",t5);
					break;
				}
				case 6 :
				{
					printf("%s\n",t1);
					printf("%s\n",t2);
					printf("%s\n",t3);
					printf("%s\n",t4);
					printf("%s\n",t5);
					printf("%s\n",t6);
					break;
				}
			}
			for(j = (6 - i); j > 0; j--)
			{
				printf("|                                                                      |\n");
			}
			Credit(name,money,time);
			if(i != 6)
			{
				sleep(1);
				system("cls");
			}
			else
			{
				sleep(2);
				system("cls");
			}
		 }
	} while(i != -1);
}
void Credit (char *name, int money, int time)
/* Prosedur untuk tampilan credit */
{
	//Kamus

	//Algoritma
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("|                              STATISTIC                               |\n");
	printf("|                                                                      |\n");
	printf("|       Name :                   Money :                  Time :       |\n");
	printf("|       %-20s     %-12d             %-12d |\n", name, money, time);
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("|                                CREDIT                                |\n");
	printf("|                                                                      |\n");
	printf("|                    13516080 - Putra Hardi Ramadhan                   |\n");
	printf("|                    13517059 - Nixon Andhika                          |\n");
	printf("|                    13517116 - Ferdy Santoso                          |\n");
	printf("|                    13517131 - Jan Meyer Saragih                      |\n");
	printf("|                    13517137 - Vincent Budianto                       |\n");
	printf("|______________________________________________________________________|\n");
}

/* ********** Tampilan Lain ********** */
void Legend ()
/* Prosedur untuk tampilan legenda */
{
	//Kamus

	//Algoritma
	system("cls");
	printf(" ______________________________________________________________________ \n");
	printf("|                                                                      |\n");
	printf("|                              LEGENDS                                 |\n");
	printf("|                                                                      |\n");
	printf("|      P      : player             |   C  : customer                   |\n");
	printf("|      X      : kursi kosong       |   T  : tray                       |\n");
	printf("| Ruangan (P) : ruangan p          |  'n' : meja no 'n' (n = integer)  |\n");
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("|                             COMMANDS                                 |\n");
	printf("|                                                                      |\n");
	printf("|     GU    : Gerak ke atas            CH    : Mengosongkan tangan     |\n");
	printf("|     GD    : Gerak ke bawah           CT    : Mengosongkan tray       |\n");
	printf("|     GL    : Gerak ke kiri            PLACE : Menaruh customer ke     |\n");
	printf("|     GR    : Gerak ke kanan                   meja sebelah player     |\n");
	printf("|     ORDER : Mengambil order dari     GIVE  : Memberi makanan paling  |\n");
	printf("|             meja berisi customer             atas tray ke meja       |\n");
	printf("|             sebelah player                   sebelah player          |\n");
	printf("|     PUT   : Membuat dan menaruh      RECIPE: Menampilkan pohon resep |\n");
	printf("|             makanan dari hand ke                                     |\n");
	printf("|             tray                     EXIT  : Keluar dari program     |\n");
	printf("|     TAKE  : Mengambil bahan di                                       |\n");
	printf("|             meja dapur sebelah                                       |\n");
	printf("|             player                                                   |\n");
	printf("|______________________________________________________________________|\n");
}
