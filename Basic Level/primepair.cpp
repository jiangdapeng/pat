#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int n)
{
  if(n == 2) return true;
  for(int i=2;i<= int(sqrt(n));++i)
  {
    if(n%i ==0)
      return false;
  }
  return true;
}

int count_prime_pairs(int n)
{
  int count = 0;
  bool pre = false;
  for(int i=3;i<=n;i+=2)
  {
    if(isprime(i))
    {
      if(pre == false)
        pre = true;
      else
      {
        count +=1;
      }
    }
    else
    {
      pre = false;
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  cout << count_prime_pairs(n)<<endl;
  return 0;
}
