#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool larger(const int a, const int b)
{
  return a > b;
}


int main()
{
  int n;
  cin >> n;
  map<int,bool> accessed;
  vector<int> inputs;
  vector<int> key_nums;
  int k;
  for(int i=0;i<n;++i)
  {
    cin >> k;
    inputs.push_back(k);
    if(accessed.find(k) != accessed.end())
      continue;
    else
    {
      while(k != 1)
      {
        if( k%2 ==0)
        {
          // even
          k = k/2;
        }
        else
        {
          k = (3*k+1)/2;
        }
        if(accessed.find(k) != accessed.end())
          break;
        else
          accessed[k] = true;
      }
    }
  }
  for(vector<int>::iterator it = inputs.begin(); it != inputs.end();++it)
  {
     if(accessed.find(*it) == accessed.end())
     {
       // hasn't been couvered
       key_nums.push_back(*it);
     }
  }
  // sort
  sort(key_nums.begin(), key_nums.end(), larger);
  cout << key_nums[0];
  for(int i=1;i<key_nums.size();++i)
  {
    cout<<" "<<key_nums[i];
  }
  cout << endl;
  return 0;
}
