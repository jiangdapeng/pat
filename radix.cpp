#include <iostream>
#include <string>
using namespace std;

int char2int(char c)
{
  int digit = 0;
  if('0' <= c && c <= '9')
    digit = c - '0';
  else
    digit = c - 'a' + 10;
  return digit;
}

int min_radix(const string& num)
{
  // find the min legal radix of num
  int radix = 1;
  int tmp;
  for(int i=0;i<num.size();++i)
  {
    tmp = char2int(num[i]);
    if(radix < tmp)
      radix = tmp;
  }
  return radix + 1;
}

int other2deci(const string& num, int radix)
{
  int result = 0;
  int digit = 0;
  for(int i=0;i<num.size();++i)
  {
    digit = char2int(num[i]);
    result  = radix * result + digit;
  }
  return result;
}

int main()
{
  string a;
  string b;
  int flag;
  int radix;
  int deci = 0;
  int radix_guess = 0;
  int startradix = 0;
  cin >> a >> b >> flag >> radix;
  string unknow = b;
  if(flag == 1)
  {
    deci = other2deci(a,radix);
  }
  else
  {
    deci = other2deci(b,radix);
    unknow = a;
  }
  startradix = min_radix(unknow);
  bool find = false;
  for(int i=startradix;i<=36;++i)
  {
    int guess = other2deci(unknow,i);
    if(guess == deci)
    {
      radix_guess = i;
      find = true;
      break;
    }
  }
  if(find)
  {
    cout << radix_guess << endl;
  }
  else
    cout << "Impossible" << endl;
  return 0;
}
