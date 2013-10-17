/**
 * 1. take care of the upper bound of radix(no upper bound)
 *
 */
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

long long min_radix(const string& num)
{
  // find the min legal radix of num
  long long radix = 1;
  long long tmp;
  for(int i=0;i<num.size();++i)
  {
    tmp = char2int(num[i]);
    if(radix < tmp)
      radix = tmp;
  }
  return radix + 1;
}

long long other2deci(const string& num, long long radix)
{
  long long result = 0;
  int digit = 0;
  for(int i=0;i<num.size();++i)
  {
    digit = char2int(num[i]);
    result  = radix * result + digit;
  }
  return result;
}


bool exists(const string& a, const string& b, long long radixa ,long long & radixb)
{ 
  long long deci = 0;
  deci = other2deci(a,radixa);
  long long startradix = min_radix(b);
  long long end = deci > startradix? deci: startradix + 1;

  bool find = false;
  for(long long i=startradix;i<=end;++i)
  {
    long long guess = other2deci(b,i);
    if(guess == deci)
    {
      radixb = i;
      find = true;
      break;
    }
    else if(guess > deci)
      break;// can't be found
    else
    {
      // using binary search
      guess = other2deci(b,(end+i)/2);
      if(guess >= deci)
      {
        // reduce upper bound
        end = (end+i)/2;
      }
      else if(guess < deci)
      {
        // increase lower bound
        i = (end+i)/2;
      }
    }
  }

  return find;
}

int main()
{
  string a;
  string b;
  int flag;
  long long radix;
  long long deci = 0;
  long long radix_guess = 0;
  long long startradix = 0;
  cin >> a >> b >> flag >> radix;

  if(flag == 2)
  {
    // swap a b
    string tmp = a;
    a = b;
    b = tmp;
  }

  if(exists(a, b, radix, radix_guess))
  {
    cout << radix_guess << endl;
  }
  else
    cout << "Impossible" << endl;
  return 0;
}
