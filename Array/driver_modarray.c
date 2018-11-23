/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : array_driver.c
 * Topik     : ADT ARRAY
 * Tanggal   : 13 September 2018
 * Deskripsi : Driver ADT ARRAY */

#include <stdio.h>
#include "modarray.c"

int main()
{
	//KAMUS
	int choice;
	TabInt T;
	ElType temp;

	//ALGORITMA
	printf("1. CreateEmptyArray");
	printf("2. GetFirstIdxArray");
	printf("3. GetLastIdxArray");
	printf("4. IsEmptyArray");
	printf("5. IsFullArray");
	printf("6. DelEli");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
		{
			CreateEmptyArray(&T);
			break;
		}
		case 2:
		{
			print("First Idx : %d\n", GetFirstIdxArray(T));
			break;
		}
		case 3:
		{
			print("Last Idx : %d\n", GetLastIdxArray(T));
			break;
		}
		case 4:
		{
			if (IsEmptyArray(T))
			{
				printf("kosong\n");
			}
			else
			{
				printf("isi\n");
			}
			break;
		}
		case 5:
		{
			if (IsFullArray(T))
			{
				printf("isi\n");
			}
			else
			{
				printf("kosong\n");
			}
			break;
		}
		case 6:
		{

			DelEli(&T, i &temp);
			printf("elemen terbuang : %d\n", temp);
			break;
		}
	}
	return 0;
}
