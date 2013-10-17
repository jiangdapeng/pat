#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_SIZE = 300;
const int MAX_LEN = 15;

struct Student
{
  char id[MAX_LEN];
  int score;
  int location;
  int local_rank;
};

int local_sort(const Student& a, const Student& b)
{
  if(a.score > b.score) return true;
  else if(a.score == b.score) return strcmp(a.id, b.id) < 0;
  else return false;
}

int main()
{
  int n,k;
  Student loc[MAX_SIZE];
  vector<Student> all;
  scanf("%d", &n);
  for(int i=0;i<n; ++i)
  {
    scanf("%d", &k);
    int location = i+1;
    for(int j=0; j<k; ++j)
    {
      scanf("%s %d",&(loc[j].id),&(loc[j].score));
      loc[j].location = location;
    }
    sort(loc,loc+k,local_sort);
    int rank = 0;
    int prescore = -1;
    for(int j=0;j<k;++j)
    {
      if(loc[j].score != prescore)
      {
        prescore = loc[j].score;
        rank = j+1;
        loc[j].local_rank = rank;
      }
      else
      {
        loc[j].local_rank = rank;
      }
    }
    all.insert(all.begin(),loc,loc+k);
  }

  sort(all.begin(), all.end(), local_sort);
  int grank = 0;
  int gprescore = -1;
  vector<Student>::iterator it;
  int count = 0;
  printf("%d\n", all.size());
  for(it = all.begin(); it != all.end(); ++it)
  {
    count++;
    if(it->score != gprescore)
    {
      gprescore = it->score;
      grank = count;
    }
    printf("%s %d %d %d\n",it->id, grank, it->location, it->local_rank);
  }
  return 0;
}
