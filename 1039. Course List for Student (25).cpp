#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_HASH_CODE = 26 * 6760;

int my_hash(const char* name)
{
  return (name[0]-'A')*6760 + (name[1]-'A')*260 + (name[2]-'A')*10+ (name[3] - '0');
}

int main()
{
  int n,k;
  vector<vector<int> > stu_course(MAX_HASH_CODE);
  scanf("%d %d", &n, &k);
  int c,s;
  char name[5];
  for(int i=0;i<k;++i)
  {
    scanf("%d %d",&c, &s);
    for(int j=0;j<s;++j)
    {
      scanf("%s",name);
      stu_course[my_hash(name)].push_back(c);
    }
  }
  for(int i=0;i<n;++i)
  {
    scanf("%s",name);
    int iname = my_hash(name);
    sort(stu_course[iname].begin(),stu_course[iname].end());
    int size = stu_course[iname].size();
    printf("%s %d",name,size);
    for(int j=0;j<size;++j)
      printf(" %d",stu_course[iname][j]);
    printf("\n");
  }
  return 0;
}
