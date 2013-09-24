/*
 *  according to my test, 0 0.0 0.00 ... should be formated as 0.000(k 0s)*10^0
 */
#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 205;

int chop1(char f[], char result[], int digits)
{
  int len = strlen(f);
  int i = 0;
  int exp = 0;
  int count = 0;
  while(i < len)
  {
    if(f[i] == '.') break;
    i++;
  }
  if(i < len)
  {
    // '.' found
    if(f[0] == '0')
    {
      // 0.abc
      i++;// skip '.'
      while(f[i] == '0') 
      {
        i++;
        exp --;
      }
      if(i == len)
      {
        // 0.0...0 is still 0
        exp = 0;
      }
      // after skip all 0.0..0abc zeros
      while(i < len && count < digits)
      {
        result[count++] = f[i++];
      }
    }
    else
    {
      // a.bcd
      exp = i;
      i = 0;
      while(i < len && count < digits)
      {
        if(f[i] != '.')
          result[count++] = f[i++];
        else
          i++;
      }
    }
  }
  else
  {
    // no '.' in f
    // special case for 0
    if(f[0] == '0')
      exp = 0;
    else
      exp = len;
    while(count < len && count < digits)
    {
      result[count] = f[count];
      count++;
    }
  }
  while(count < digits)
  {
    result[count++] = '0';
  }
  result[digits] = '\0';
  return exp;
}

int main()
{
  int digits;
  char f1[MAX_SIZE];
  char f2[MAX_SIZE];
  char r1[MAX_SIZE];
  char r2[MAX_SIZE];
  scanf("%d %s %s",&digits, f1, f2);
  int exp1 = chop1(f1,r1,digits);
  int exp2 = chop1(f2,r2,digits);
  if(exp1 == exp2 && strcmp(r1,r2)==0)
  {
    printf("YES 0.%s*10^%d\n", r1, exp1);
  }
  else
  {
    printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1, exp1, r2, exp2);
  }
  return 0;
}
