#include <iostream>
#include <string>
using namespace std;

int main()
{
  string line;
  cin >> line;
  int n1,n2,n3;
  int len = line.length();
  n1 = n3 = (len+2) / 3;
  n2 = n1 + (len+2) % 3;
  for(int i=0;i<n1-1;++i)
  {
    cout << line[i];
    for(int j=0;j<n2-2;++j)
    {
      // cout n2-2 space
      cout << " ";
    }
    cout << line[len-1-i] << endl;
  }
  for(int i=n1-1;i<n1-1+n2;++i)
  {
    cout << line[i];
  }
  cout << endl;
  return 0;
}
