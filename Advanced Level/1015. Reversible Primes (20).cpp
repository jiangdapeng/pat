#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

bool isprime(int n)
{
  if(n < 2)
    return false;
  int stop = (int)sqrt(n);
  for(int i=2;i<=stop;++i)
  {
    if(n % i == 0)
      return false;
  }
  return true;
}

int reverse(int n,int d)
{
  vector<int> digits;
  do
  {
    digits.push_back(n%d);
    n /= d;
  }while(n>0);
  int result = 0;
  for(int i=0;i<digits.size();++i)
  {
    result = result*d + digits[i];
  }
  return result;
}

int main()
{
  int n;
  int d;
  while(true)
  {
    cin >> n;
    if(n < 0)
      break;
    cin >> d;
    if(isprime(n) && isprime(reverse(n,d)))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
