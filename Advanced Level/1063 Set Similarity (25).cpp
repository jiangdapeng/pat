#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// assume a, b are sorted and uniqued
double set_similarity(const vector<int>& a, const vector<int>& b)
{
  int count_both = 0;
  int count_either = 0;
  int i = 0;
  int j = 0;
  int n1 = a.size();
  int n2 = b.size();
  while(i < n1 && j < n2)
  {
    count_either++;
    if(a[i] == b[j])
    {
      count_both++;
      i++;
      j++;
    }
    else if(a[i] < b[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  if(i == n1) count_either += n2 - j;
  if(j == n2) count_either += n1 - i;
  return (double)count_both / (double)count_either;
}

int main()
{
  int n ;// number of sets
  int m; // number of elems in one set
  int k; // number of queries
  int e;
  vector<vector<int> > sets;
  vector<bool> visited(51,false);
  scanf("%d", &n);
  for(int i=0;i<n;++i)
  {
    scanf("%d", &m);
    vector<int> s;
    for(int j=0;j<m;++j)
    {
      scanf("%d", &e);
      s.push_back(e);
    }
    sets.push_back(s);
  }
  int s1, s2;
  scanf("%d", &k);
  vector<int>::iterator it;
  for(int i=0;i<k;++i)
  {
    scanf("%d %d", &s1, &s2);
    if(!visited[s1])
    {
      visited[s1] = true;
      sort(sets[s1 -1].begin(), sets[s1 - 1].end());
      it = unique(sets[s1 -1].begin(), sets[s1 - 1].end());
      sets[s1 - 1].resize(distance(sets[s1 - 1].begin(), it));
    }
    if(!visited[s2])
    {
      visited[s2] = true;
      sort(sets[s2 -1].begin(), sets[s2 - 1].end());
      it = unique(sets[s2 -1].begin(), sets[s2 - 1].end());
      sets[s2 - 1].resize(distance(sets[s2 - 1].begin(), it));
    }
    printf("%.1f%\n",100 * set_similarity(sets[s1 - 1], sets[s2 - 1]));
  }
  return 0;
}
