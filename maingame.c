#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  MainMenu();
  int choice;
  char *command;
  char *playername;
  command = (char *) malloc (6 * sizeof(char)); //Alokasi string command sepanjang 6 karakter
  playername = (char *) malloc (12 * sizeof(char)); //Alokasi nama player sepanjang 12 karakter
  strcpy(playername,""); //Inisialisasi string nama player
  scanf("%d", &choice); //Membaca pilihan dari player
  switch(choice){
    case 1:{
      NewGame(playername);
      StartGame(playername);
      break;
    }
    case 2:{
      StartGame(playername);
      break;
    }
    case 3:{
      //LoadGame();
      break;
    }
    case 4:{
      exit(0);
    }
  }
  return 0;
}
