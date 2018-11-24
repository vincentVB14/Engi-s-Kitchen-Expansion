#include <stdio.h>
#include "boolean.h"

int FakeStrCmp (char* str1, char* str2);

int FakeStrNCmp (char* str1, char* str2, int N);

void FakeStrCpy (char* str1, char* str2);

int FakeAtoi (char* str1);

int main()
{
  // KAMUS
  char str1[20];
  char str2[20];
  boolean same;
  int choice;
  int chars;

  // ALGORITMA
  printf("Choices ....\n1. FakeStrCmp\n2. FakeStrNCmp\n3. FakeStrCpy\n4. FakeAtoi\n5. Exit\n");
  printf("Choice = ");
  scanf("%d", &choice);

  while (choice != 5)
  {
    switch (choice) {
      case 1:
        printf("Str 1 = ");
        scanf("%s", str1);
        printf("Str 2 = ");
        scanf("%s", str2);
        if (FakeStrCmp(str1, str2) == 0)
        {
          printf("Kedua string sama\n");
        }
        else
        {
          printf("Kedua string tidak sama\n");
        }
        break;
      case 2:
        printf("Str 1 = ");
        scanf("%s", str1);
        printf("Str 2 = ");
        scanf("%s", str2);
        printf("Berapa banyak char : ");
        scanf("%d", &chars);
        if (FakeStrNCmp(str1, str2, chars) == 0)
        {
          printf("Kedua string sama\n");
        }
        else
        {
          printf("Kedua string tidak sama\n");
        }
        break;
      case 3:
        printf("Str yang ingin dicopy : ");
        scanf("%s", str1);
        FakeStrCpy(str1, str2);
        printf("Hasil kopian : %s\n", str2);
        break;
      case 4:
        printf("Str yang ingin diubah ke integer : ");
        scanf("%s", str1);
        printf("Hasil integernya : %d\n", FakeAtoi(str1));
        break;
      default:
        printf("Wrong input. Try again\n");
    }
    printf("Choices ....\n1. FakeStrCmp\n2. FakeStrNCmp\n3. FakeStrCpy\n4. FakeAtoi\n5. Exit\n");
    printf("Choice = ");
    scanf("%d", &choice);
  }
}

int FakeStrCmp (char* str1, char* str2)
{
  boolean same;

  same = true;

  while (*str1 != '\0' && *str2 != '\0' && same)
  {
    if (*str1 == *str2)
    {
      str1++;
      str2++;
    }
    else
    {
      same = false;
    }
  }
  if (same && *str1 == '\0' && *str2 == '\0')
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int FakeStrNCmp (char* str1, char* str2, int N)
{
  boolean same;
  same = true;

  while (N > 0 && *str1 != '\0' && *str2 != '\0' && same)
  {
    if (*str1 == *str2)
    {
      str1++;
      str2++;
      N--;
    }
    else
    {
      same = false;
    }
  }
  if (N == 0 && same)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void FakeStrCpy (char* str1, char *str2)
{
  while (*str1 != '\0')
  {
    *str2 = *str1;
    *str1++;
    *str2++;
  }
  *str2 = '\0';
}

int FakeAtoi (char* str1)
{
  int Acc;
  Acc = 0;

  while (*str1 != '\0')
  {
    Acc = Acc * 10 + (*str1 - '0');
    str1++;
  }
  return (Acc);
}
