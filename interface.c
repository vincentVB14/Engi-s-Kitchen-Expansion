/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: interface.c */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Realisasi Modul Interface */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "kamus.h"
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
	for(i = 0; i < 7; i++)
	{
		printf("|----------------------------------------------------------------------------------|\n");
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
		for(j = (7 - i); j > 0; j--)
		{
			printf("|                                                                                  |\n");
		}
		printf("|----------------------------------------------------------------------------------|\n");
		if(i != 6)
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
					if(CurrentRoom(G) == 4){
						printf("P");
					} else{
						printf("P ");
					}
					break;
				}
				case ('L'):     // Lantai
				{
					if(CurrentRoom(G) == 4){
						printf(" ");
					} else{
						printf("  ");
					}
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
					if(CurrentRoom(G) == 4){
						printf("M");
					} else{
						printf("%-2s", MElmt3(Ruangann(P),i,j));
					}
					break;
				}
				case ('T'):
				{
					printf("T");
				}
			}
			if (j != GetLastIdxKolMatrix(Ruangann(P)))
			{
				printf(" | ");
			}
			else if (i <= GetLastIdxBrsMatrix(Ruangann(P)))
			{
				printf(" | *********************** |\n");
				if(CurrentRoom(G) == 4){
					printf("|----------------------------------------------------------------------------------|\n");
				} else{
					printf("|------------------------------------------------------------------------------------------|\n");
				}
			}
		}
	}
	printf("| ********************** |\n");
}

//void Info (Queue Q, TabInt T, TabInt O, TabInt H)
/* Prosedur untuk tampilan informasi saat permainan berlangsung */
/*
		s = '-';
	}
	printf("| Info : %-73s |", s);
	printf("|----------------------------------------------------------------------------------|\n");
	printf("| Waiting Customer:                      |  Food Tray:                             |\n");
	printf("|  1. %-34s |   1. %-34s |\n", Q[1], T[1]);
	printf("|  2. %-34s |   2. %-34s |\n", Q[2], T[2]);
	printf("|  3. %-34s |   3. %-34s |\n", Q[3], T[3]);
	printf("|  4. %-34s |   4. %-34s |\n", Q[4], T[4]);
	printf("|  5. %-34s |   5. %-34s |\n", Q[5], T[5]);
	printf("|----------------------------------------------------------------------------------|\n");
	printf("| Waiting Customer:                      |  Food Tray:                             |\n");
	printf("|  1. %-34s |   1. %-34s |\n", O[1], H[1]);
	printf("|  2. %-34s |   2. %-34s |\n", O[2], H[2]);
	printf("|  3. %-34s |   3. %-34s |\n", O[3], H[3]);
	printf("|  4. %-34s |   4. %-34s |\n", o[4], H[4]);
	printf("|  5. %-34s |   5. %-34s |\n", O[5], H[5]);
}*/

void Play (char *name, int money, int life, int time, Gaddress P, Graph G)
/* Prosedur untuk tampilan saat permainan berlangsung */
{
	//Kamus

	//Algoritma
	if(CurrentRoom(G) == 4){
		printf("____________________________________________________________________________________\n");
		printf("| %-12s | Money: %-12d | Life: %-12d | Time: %-12d     |\n", name, money, life, time);
		printf("|----------------------------------------------------------------------------------|\n");
		printf("|                                    Dapur                                         |\n");
		printf("|----------------------------------------------------------------------------------|\n");
		Room(P, G);
		printf("|----------------------------------------------------------------------------------|\n");
		//Info(Q,T,O,H);
		printf("|__________________________________________________________________________________|\n");
	} else{
		printf("____________________________________________________________________________________________\n");
		printf("| %-12s | Money: %-12d | Life: %-12d | Time: %-12d             |\n", name, money, life, time);
		printf("|------------------------------------------------------------------------------------------|\n");
		printf("|                                      Ruangan  %d                                          |\n", Nomor(P));
		printf("|------------------------------------------------------------------------------------------|\n");
		Room(P, G);
		printf("|------------------------------------------------------------------------------------------|\n");
		//Info(Q,T,O,H);
		printf("____________________________________________________________________________________________\n");
	}

}

/* ********** Tampilan Setelah Permainan Berakhir ********** */
/*void GameOver (stat s)
/* Prosedur untuk tampilan game over */
/*{
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
			for(j = (7 - i); j > 0; j--)
			{
				printf("|                                                                      |\n");
			}

			Credit(s);
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
void Credit (Stat s) */
/* Prosedur untuk tampilan credit */
//{
	//Kamus

	//Algoritma
/*	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("|                              STATISTIC                               |\n");
	printf("|                                                                      |\n");
	printf("|               Name :           Money :          Time :               |\n");
	printf("|               %_12s     %_12d     %_12d         |\n", Name(s), Money(s), Time(s));
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("|                                CREDIT                                |\n");
	printf("|                                                                      |\n");
	printf("|                    13516080 _ Putra Hardi Ramadhan                   |\n");
	printf("|                       13517059 _ Nixon Andhika                       |\n");
	printf("|                       13517116 _ Ferdy Santoso                       |\n");
	printf("|                     13517131 _ Jan Meyer Saragih                     |\n");
	printf("|                     13517137 _ Vincent Budianto                      |\n");
	printf("|______________________________________________________________________|\n");
}*/

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
	printf("| P : player                       |   C  : customer                   |\n");
	printf("| X : kursi kosong                 |   T  : tray                       |\n");
	printf("| Ruangann(P) : meja bahan         |  'n' : meja no 'n' (n = integer)  |\n");
	printf("|______________________________________________________________________|\n");
}
