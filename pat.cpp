/*
 * YES:
 *    A^nPA^kTA^(k*n)  k>=1, n>=0
 * NO:
 *    OTHER
 *
 */
#include <iostream>
#include <stdio.h>

using namespace std;

const int STATE_A1 = 0;
const int STATE_P = 1;
const int STATE_A2 = 2;
const int STATE_T = 3;
const int STATE_A3 = 4;

bool pat(const char* str)
{
  int p = 0;
  int t = 0;
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;
  int i=0;
  int state = STATE_A1;
  char c;
  while(str[i] != '\0')
  {
    c = str[i];
    if(str[i] != 'P' &&  str[i] != 'A' && str[i] != 'T')
    {
      return false;
    }

    switch(state)
    {
      case STATE_A1:
        if(c == 'A')
        {
          a1++;
        }
        else if(c == 'P')
        {
          state = STATE_P;
          p++;
        }
        else
          return false;
        break;
      case STATE_P:
        if(c == 'A')
        {
          state = STATE_A2;
          a2++;
        }
        else 
          return false;
        break;
      case STATE_A2:
        if(c == 'A')
        {
          a2++;
        }
        else if(c == 'T')
        {
          state = STATE_T;
          t++;
        }
        else
          return false;
        break;
      case STATE_T:
        if(c == 'A')
        {
          state = STATE_A3;
          a3++;
        }
        else
          return false;
        break;
      case STATE_A3:
        if(c == 'A')
        {
          a3++;
        }
        else
          return false;
        break;
    }//end of switch
    ++i;
  }//end of while
  if((p==1) && (t ==1) && (a2 >0) && (a3 == a2*a1))
  {
    return true;
  }
  else return false;
}

int main()
{
  int n;
  cin >> n;
  char str[110];
  while(n--)
  {
    scanf("%s",str);
    if(pat(str))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
