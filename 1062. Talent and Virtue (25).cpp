#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct People
{
  char id[10];
  int virtue;
  int talent;
};

int L,H;

int level(const People& p)
{
  if(p.virtue >= H && p.talent >=H)
    return 3;
  else if(p.virtue >= H && p.talent >= L)
    return 2;
  else if(p.virtue >= p.talent && p.talent >= L && p.virtue < H)
    return 1;
  else
    return 0;
}

bool smg_sort(const People& a, const People& b)
{
  int levela = level(a);
  int levelb = level(b);
  if(levela > levelb) return true;
  else if(levela == levelb)
  {
    int ta = a.virtue + a.talent;
    int tb = b.virtue + b.talent;
    if(ta > tb) return true;
    else if(ta == tb)
    {
      if(a.virtue > b.virtue) return true;
      else if(a.virtue == b.virtue)
      {
        return strcmp(a.id, b.id) < 0;
      }
      else return false;
    }
    else return false;
  }
  else return false;
}

int main()
{
  int n;
  vector<People> ps;
  People tmp;
  scanf("%d %d %d",&n, &L, &H);
  for(int i=0; i<n; ++i)
  {
    scanf("%s %d %d",tmp.id, &tmp.virtue, &tmp.talent);
    if(tmp.virtue >=L && tmp.talent >= L)
      ps.push_back(tmp);
  }
  sort(ps.begin(), ps.end(), smg_sort);
  printf("%d\n",ps.size());
  vector<People>::iterator it = ps.begin();
  for(;it != ps.end();++it)
  {
    printf("%s %d %d\n", it->id, it->virtue, it->talent);
  }
  return 0;
}
