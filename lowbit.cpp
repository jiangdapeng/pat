#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  do
  {
    cin >> n;
    cout << hex << n << endl;
    cout << hex << -n << endl;
    cout << (n & -n) << endl;
  }while(n!=0);
  return 0;
}
