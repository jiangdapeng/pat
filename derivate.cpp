#include <iostream>

using namespace std;


int main()
{
  int coe =0;
  int exp = 0;
  int preexp = 0;
  int precoe = 0;
  bool first = true;
  cin >> coe >> exp;
  preexp = exp;
  precoe = coe*exp;
  while( cin >> coe >> exp )
  {
    if(exp == 0)
      break;
    if(exp == preexp)
    {
      precoe += exp*coe;
    }
    else
    {
      if(first)
      {
        first = false;
      }
      else 
      {
        cout << " ";
      }
      cout << precoe << " " << preexp-1;
      precoe = exp*coe;
      preexp = exp;
    }
  }
  if(!first)
  {
    cout << " ";
  }
  cout << precoe << " " << preexp-1;
  cout << endl;
  return 0;
}
