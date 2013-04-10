#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int longest(char * str)
{
  int max = 1;
  char *tmp = str;
  char *left = str;
  char *right = str;
  while(*tmp != '\0')
  {
    // not 
    // odd
    left = tmp - 1;
    right = tmp + 1;
    int count = 1;
    while(left >= str && *right!='\0' && *left == *right)
    {
      count += 2;
      --left;
      ++right;
    }
    if(count > max)
      max = count;
    // even
    left = tmp;
    right = tmp + 1;
    count = 0;
    while(left >= str && *right != '\0' && *left == *right)
    {
      count += 2;
      --left;
      ++right;
    }
    if(count > max)
    {
      max = count;
    }
    ++tmp;
  }
  return max;
}

int main()
{
  char input[1001];
  gets(input);
  cout << longest(input)<<endl;
  return 0;
}
