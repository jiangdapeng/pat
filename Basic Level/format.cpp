#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int bai = n/100;
  n = n%100;
  int ten = n/10;
  n = n%10;
  int one = n;
  for(int i=0;i<bai;++i)
  {
    cout<<"B";
  }

  for(int i=0;i<ten;++i)
  {
    cout<<"S";
  }

  for(int i=1;i<=one;++i)
  {
    cout<<i;
  }
  cout << endl;
  return 0;
}
