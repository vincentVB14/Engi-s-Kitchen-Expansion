#include <stdio.h>
#include "boolean.h"
#include "fakestring.h"

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
  while (*str2 != '\0')
  {
    *str1 = *str2;
    *str1++;
    *str2++;
  }
  *str1 = '\0';
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
