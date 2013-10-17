#include <iostream>
using namespace std;

long long count(int n)
{
  long long count =0;
  while(n != 1)
  {
    if( n%2 ==0)
    {
      // even
      n = n / 2;
    }
    else
    {
      n = (3*n+1)/2;
    }
    count += 1;
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  cout << count(n) <<endl;
  return 0;
}
