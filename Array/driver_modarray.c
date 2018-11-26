/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : array_driver.c
 * Topik     : ADT ARRAY
 * Tanggal   : 13 September 2018
 * Deskripsi : Driver ADT ARRAY */

#include <stdio.h>
#include <fakestring.h>
#include "modarray.c"

int main()
{
	//KAMUS
	int cek;
	int choice;
	int i;
	TabInt T;
	ElType temp;

	//ALGORITMA
	cek = 1;
	CreateEmptyArray(&T);
	printf("Jumlah isi array : %d\n", Neff(T));
	printf("Input isi array :\n");
	BacaIsi(&T);
	do
	{
		printf("Jumlah isi array : %d\n", Neff(T));
		printf("1. TulisIsi\n");
		printf("2. GetFirstIdxArray\n");
		printf("3. GetLastIdxArray\n");
		printf("4. IsEmptyArray\n");
		printf("5. IsFullArray\n");
		printf("6. DelEli\n");
		printf("choice = "); scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				TulisIsiArray(T);
				break;
			}
			case 2:
			{
				printf("First Idx : %d\n", GetFirstIdxArray(T));
				break;
			}
			case 3:
			{
				printf("Last Idx : %d\n", GetLastIdxArray(T));
				break;
			}
			case 4:
			{
				if (IsEmptyArray(T))
				{
					printf("kosong\n");
				}
				else if (!IsEmptyArray(T))
				{
					printf("isi\n");
				}
				break;
			}
			case 5:
			{
				if (IsFullArray(T))
				{
					printf("penuh\n");
				}
				else if (!IsFullArray(T))
				{
					printf("kosong\n");
				}
				break;
			}
			case 6:
			{
				scanf("%d", &i);
				DelEli(&T, i, &temp);
				TulisIsi(T);
				break;
			}
			case 7:
			{
				cek = 1;
				break;
			}
		}
	} while (cek != 0);
	return 0;
}
