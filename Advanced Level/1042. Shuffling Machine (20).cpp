#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> shuffle(vector<int>& seq,const vector<int>& order, int k)
{
  vector<vector<int> > swap(2);
  vector<int> tmp(55);
  swap[0] = tmp;
  swap[1] = seq;

  int cur = 0;
  int pre = 1;
  for(int i=0;i<k;++i)
  {
    // repeat times
    cur = i % 2;
    pre = cur==0?1:0;
    for(int p = 1;p<55;++p)
    {
      swap[cur][order[p]] = swap[pre][p];
    }
  }
  return swap[cur];
}

void output(const vector<int>& result)
{
  char flower[] = {'S','H','C','D','J'};

  int num = result[1];
  int f = (num-1) / 13;
  int n = (num-1) % 13+1;
  cout <<  flower[f] << n;

  for(int i=2;i<55;++i)
  {
    num = result[i];
    int f = (num-1) / 13;
    int n = (num-1) % 13+1;
    cout << " " <<  flower[f] << n;
  }
  cout << endl;
}

int main()
{
  int k = 0;
  cin >> k;
  vector<int> order(55);
  for(int i=1;i<55;++i)
  {
    cin >> order[i];
  }
  // initial order
  vector<int> seq(55);
  for(int i=1;i<55;++i)
  {
    seq[i] = i;
  }
  vector<int> result = shuffle(seq,order,k);
  output(result);
  return 0;
}
