#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 26*26*26;

int my_hash(char* name)
{
  return (name[0] - 'A')*26*26 + (name[1] - 'A')*26 + name[2] - 'A';
}

void hash2name(int hash, char* name)
{
  name[0] = hash / (26*26) + 'A';
  hash %= 26*26;
  name[1] = hash / 26 + 'A';
  hash %= 26;
  name[2] = hash + 'A';
  name[3] = '\0';
}

vector<int> tuang(MAX_SIZE, -1);
vector<int> tuang_weight(MAX_SIZE, 0);
vector<int> weight(MAX_SIZE, 0);
vector<vector<int> > member(MAX_SIZE);

int find(int a)
{
  int next = a;
  while(tuang[next] > -1)
    next = tuang[next];
  return next;
}

int merge(int a, int b, int w)
{
  if(a > b)
  {
    int t = b;
    b = a;
    a = t;
  }
  int ra = find(a);
  int rb = find(b);
  if(ra != rb)
  {
    tuang[rb] = ra;
    tuang[ra] --;
    tuang_weight[ra] += tuang_weight[rb] + w;
    member[ra].insert(member[ra].begin(),member[rb].begin(), member[rb].end());
    member[rb].clear();
  }
  else
  {
    tuang_weight[ra] += w; // weight should be added
  }
  return ra;
}

struct Gang
{
  int name;
  int head;
};

bool head_sort(const Gang& a, const Gang& b)
{
  return a.head < b.head;
}

int main()
{
  int n,thre;
  scanf("%d %d", &n, &thre);
  char name1[4];
  char name2[4];
  int w;
  int iname1,iname2;
  for(int i=0;i<n;++i)
  {
    scanf("%s %s %d", name1, name2, &w);
    iname1 = my_hash(name1);
    iname2 = my_hash(name2);
    if(member[iname1].empty()) member[iname1].push_back(iname1);
    if(member[iname2].empty()) member[iname2].push_back(iname2);
    weight[iname1] += w;
    weight[iname2] += w;
    merge(iname1, iname2, w);
  }
  vector<Gang> gang;
  Gang tmp;
  for(int i=0;i<MAX_SIZE; ++i)
  {
    if(tuang[i]  < -1)
    {
      if(tuang_weight[i]>thre && member[i].size()>2)
      {
        tmp.name = i;
        // find head of a gang
        int max_idx = 0;
        for(int j=1;j<member[i].size();++j)
        {
          if(weight[member[i][j]] > weight[member[i][max_idx]])
            max_idx = j;
        }
        tmp.head = member[i][max_idx];
        gang.push_back(tmp);
      }
    }
  }
  sort(gang.begin(),gang.end(), head_sort);
  int size = gang.size();
  printf("%d\n",size);
  for(int i=0;i<size;++i)
  {
    hash2name(gang[i].head,name1);
    printf("%s %d\n", name1, member[gang[i].name].size());
  }
  return 0;
}
