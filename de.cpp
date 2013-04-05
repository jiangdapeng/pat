#include <iostream>

using namespace std;


int main()
{
  int coe =0;
  int exp = 0;
  bool first = true;
  while( cin >> coe >> exp )
  {
    if(exp == 0)
      break;
    if(first)
    {
      first = false;
    }
    else
    {
      cout << " ";
    }
    cout << coe*exp << " " << exp-1;
  }
  cout << endl;
  return 0;
}
