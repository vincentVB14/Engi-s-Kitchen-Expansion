/* Nama Kelompok	: Jangan Skip Ujay */
/* NIM/Nama			: 13516080/Putra Hardi Ramadhan, 13517059/Nixon Andhika, 13517116/Ferdy Santoso, 13517131/Jan Meyer Saragih, 13517137/Vincent Budianto */
/* Nama file 		: driver_modpoint.c */
/* Topik			: Tugas Besar IF2110 - Algoritma dan Struktur Data */
/* Tanggal			: 26 November 2018 */
/* Deskripsi		: Definisi Modul Kamus */

#include "modpoint.c"

int main()
{
  // KAMUS
  POINT P1, P2;
  int choice;
  int X, Y;

  // ALGORITMA
  P1 = MakePOINT(0,0);
  P2 = MakePOINT(0,0);
  printf("DRIVER DARI MODPOINT\nPoint awal : <0,0>\nList Perintah:\n");
  printf("1. MakePOINT\n2. CopyPOINT\n3. TulisPOINT\n4. Exit\n");
  scanf("%d", &choice);

  while (choice != 4) {
    switch (choice){
      case 1:
      {
        printf("Memasukkan point P1\n");
        printf("Masukkan X : ");
        scanf("%d", &X);
        printf("Masukkan Y : ");
        scanf("%d", &Y);
        P1 = MakePOINT(X,Y);
        break;
      }
      case 2:
      {
        printf("Copy point dari P1 ke P2\n");
        P2 = CopyPOINT(P1);
        break;
      }
      case 3:
      {
        printf("P1 = ");
        TulisPOINT(P1);
        printf("\nP2 = ");
        TulisPOINT(P2);
        printf("\n");
        break;
      }
      default:
      {
        printf("Invalid command\n");
      }
    }
    printf("List Perintah\n");
    printf("1. MakePOINT\n2. CopyPOINT\n3. TulisPOINT\n4. Exit\n");
    scanf("%d", &choice);
  }
}
