#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Student
{
  string no;// student number
  int c;// c programming
  int m;// math
  int e;// english
  int a;// average
};

bool greatera(const Student& s1, const Student& s2)
{
  return s1.a > s2.a;
}

bool greaterc(const Student& s1, const Student& s2)
{
  return s1.c > s2.c;
}

bool greaterm(const Student& s1, const Student& s2)
{
  return s1.m > s2.m;
}

bool greatere(const Student& s1, const Student& s2)
{
  return s1.e > s2.e;
}

char course[] = {'A','C','M','E'};

int min_index(const vector<int>& arr)
{
  int idx = 0;
  for(int i=1;i<arr.size();++i)
  {
    if(arr[idx] > arr[i])
      idx = i;
  }
  return idx;
}


int main()
{
  int n,m;
  cin >> n >> m;
  Student tmp;
  vector<Student> s;

  for(int i=0;i<n;++i)
  {
    cin >> tmp.no >> tmp.c >> tmp.m >> tmp.e;
    tmp.a = (tmp.c + tmp.m + tmp.e)/3;
    s.push_back(tmp);
  }
  sort(s.begin(),s.end(),greatera);
  map<string,vector<int> > ranks;
  for(int i=0;i<s.size();++i)
  {
    ranks[s[i].no].push_back(i+1);
  }
  sort(s.begin(),s.end(),greaterc);
  for(int i=0;i<s.size();++i)
  {
    ranks[s[i].no].push_back(i+1);
  }
  sort(s.begin(),s.end(),greaterm);
  for(int i=0;i<s.size();++i)
  {
    ranks[s[i].no].push_back(i+1);
  }
  sort(s.begin(),s.end(),greatere);
  for(int i=0;i<s.size();++i)
  {
    ranks[s[i].no].push_back(i+1);
  }
  string no;
  for(int i=0;i<m;++i)
  {
    cin >> no;
    if(ranks.find(no) == ranks.end())
    {
      cout << "N/A" << endl;
    }
    else
    {
      vector<int> rank = ranks[no];
      int idx = min_index(rank);
      cout << rank[idx] << " " << course[idx] << endl;
    }
  }
  return 0;
}
