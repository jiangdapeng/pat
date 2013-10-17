#include <iostream>
using namespace std;

const int UP=6;
const int DOWN=4;
const int STOP=5;
int main()
{
  int n;
  int cost = 0;
  cin >> n;
  int curfloor = 0;
  int prefloor = 0;
  for(int i=0;i<n;++i)
  {
    cin >> curfloor;
    if(curfloor > prefloor)
      cost += UP * (curfloor - prefloor);
    else if(curfloor < prefloor)
      cost += DOWN * (prefloor - curfloor);
    prefloor = curfloor;
  }
  cost += n * STOP;
  cout << cost << endl;
  return 0;
}
