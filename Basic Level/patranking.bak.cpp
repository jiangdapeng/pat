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

void merge_list(const vector<Record> loc[],int n, vector<Record>& result)
{
  int idx = 0;
  vector<int> indexs(MAX_LOCATIONS);
  bool done = false;
  vector<Record> top;
  while(!done)
  {
    //
    int highest = -1;
    top.clear();
    // find topest
    for(int i=0;i< n;++i)
    {
      if(indexs[i] < loc[i].size() && loc[i][indexs[i]].score > highest)
      {
        highest = loc[i][indexs[i]].score;
      }
    }
    // find record with the same score
    for(int i=0;i<n;++i)
    {
      if(indexs[i] < loc[i].size() && loc[i][indexs[i]].score == highest)
      {
        top.push_back(loc[i][indexs[i]]);
        ++indexs[i];
      }
    }
    // sort by reg_num
    sort(top.begin(),top.end(),jdpgreater);
    result.insert(result.end(),top.begin(),top.end());
    done = true;// assume done = true
    for(int i=0;i<n;++i)
    {
      if(indexs[i] < loc[i].size())
      {
        done = false;
        break;// break for loop
      }
    }
  }
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
  }
  // sort all record
  merge_list(locations,n,all);
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

