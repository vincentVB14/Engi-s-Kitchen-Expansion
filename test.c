#include <stdio.h>
#include <string.h>
#include <windows.h>

void Loading();
void MainMenu();
void Credit(char N[12], int M, int T);
void GameOver(char N[12], int M, int T);

int main()
{
	char Name[12] = "Engi";
	int Money = 20000;
	int Time = 500;	
	char choice;
	Loading();
	MainMenu();
	do
	{
		choice = getch(); //Membaca pilihan dari player
	} while ((choice != '1') || (choice != '2') || (choice != '3') || (choice != '4'));
	system("cls");
	switch (choice)
	{
		case '1':
		{
			MainMenu();
			break;
		}
		case '2':
		{
			Credit(Name, Money, Time);
			break;
		}
		case '3':
		{
			//LoadGame();
			GameOver(Name, Money, Time);
			break;
		}
		case '4':
		{
			exit(0);
		}
	}
	return 0;
}

void Loading()
/* Prosedur untuk tampilan loading sebelum permainan dimulai */
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
}
void MainMenu ()
/* Prosedur untuk tampilan menu sebelum permainan dimulai */
{
	//Kamus
	
	//Algoritma
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

void GameOver(char N[12], int M, int T)
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
			printf("|----------------------------------------------------------------------|\n");
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
			Credit(N, M, T);
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

void Credit(char N[12], int M, int T)
{
	printf("|----------------------------------------------------------------------|\n");
	printf("|                              STATISTIC                               |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|               Name :           Money :          Time :               |\n");
	printf("|               %-12s     %-12d     %-12d         |\n", N, M, T);
	printf("|----------------------------------------------------------------------|\n");
	printf("|                                CREDIT                                |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                    13516080 - Putra Hardi Ramadhan                   |\n");
	printf("|                       13517059 - Nixon Andhika                       |\n");
	printf("|                       13517116 - Ferdy Santoso                       |\n");
	printf("|                     13517131 - Jan Meyer Saragih                     |\n");
	printf("|                     13517137 - Vincent Budianto                      |\n");
	printf("|----------------------------------------------------------------------|\n");
}
