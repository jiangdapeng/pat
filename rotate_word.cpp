#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void reverse(char str[],int size)
{
  char c;
  for(int i=0;i<size/2;++i)
  {
    c = str[i];
    str[i] = str[size-1-i];
    str[size-1-i] = c;
  }
}

int main()
{
  char line[81];
  cin.getline(line,81);
  int len = strlen(line);
  reverse(line,len);
  int start = 0;
  for(int i=0;i<len;++i)
  {
    if(line[i] == ' ')
    {
      reverse(line+start,i-start);
      start = i+1;
    }
  }
  reverse(line+start,len-start);
  cout << line << endl;
  return 0;
}
