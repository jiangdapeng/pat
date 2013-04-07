#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const char* pinyin[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int digitsum(char * digits)
{
  int sum = 0;
  int i=0;
  while(digits[i] != '\0')
  {
    sum += digits[i] - '0';
    ++i;
  }
  return sum;
}
void printnumber(int n)
{
  vector<int> vi;
  do
  {
    vi.push_back(n%10);
    n /=10;
  } while(n!=0);
  int size = vi.size();
  for(int i=size-1;i>0;--i)
  {
    cout << pinyin[vi[i]] << " ";
  }
  if(size >0)
    cout << pinyin[vi[0]];
  cout << endl;
}

int main()
{
  char digits[110];
  scanf("%s",digits);
  printnumber(digitsum(digits));
  return 0;
}
