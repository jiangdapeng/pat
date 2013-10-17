/**
* the last test point out of time
* but i don't know why
* 1. the copy operation cost too much time ?
* 2. the sort of all cost too much time ?
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAX_LOCATIONS = 10;

struct Record
{
  string reg_num;
  int location;
  int score;
  int local_rank;
};

bool jdpgreater(const Record& a, const Record& b)
{
  if(a.score > b.score)
    return true;
  else if(a.score == b.score)
  {
    return a.reg_num.compare(b.reg_num) < 0;
  }
  else
    return false;
}

int main()
{
  int n,k;
  vector<Record> locations[MAX_LOCATIONS];
  vector<Record> all;
  cin >> n;
  Record tmp;
  for(int i=0;i<n;++i)
  {
    cin >> k;
    for(int j=0;j<k;++j)
    {
      cin >> tmp.reg_num;
      cin >> tmp.score;
      tmp.location = i+1;
      locations[i].push_back(tmp);
    }
  }
  for(int i=0;i<n;++i)
  {
    // sort each location
    // by score and reg_num
    sort(locations[i].begin(),locations[i].end(), jdpgreater);
    int prescore = -1;
    int rank = 0;
    for(int j=0;j<locations[i].size();++j)
    {
      // the same score, the same rank
      if(locations[i][j].score != prescore)
      {
        prescore = locations[i][j].score;
        rank = j+1;
      }
      locations[i][j].local_rank = rank;
    }
    all.insert(all.end(),locations[i].begin(),locations[i].end());
  }
  // sort all record
  sort(all.begin(),all.end(),jdpgreater);
  int prescore = -1;
  int rank = 0;
  cout << all.size() << endl;
  for(int i=0;i<all.size();++i)
  {
    if(all[i].score != prescore)
    {
      prescore = all[i].score;
      rank = i+1;
    }
    cout << all[i].reg_num << " " << rank << " " << all[i].location << " "<< all[i].local_rank << endl;
  }
  return 0;
}
