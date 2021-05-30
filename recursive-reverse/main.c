#include <stdio.h>

void reverseString(char *s, int sSize)
{
  if (sSize <= 0)  return;  
  char temp = s[0];
  s[0] = s[sSize - 1];
  s[sSize - 1] = temp;
  return reverseString(++s, sSize - 2);
}

int main()
{
  char r[] = {'h', 'e', 'l', 'l', 'o'};
  
  reverseString(r, sizeof(r));

  printf(r);
}