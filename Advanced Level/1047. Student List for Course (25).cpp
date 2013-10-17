/*
 * 直接在名字数组上排序会超时，应该是字符串的复制操作导致的
 * 因此，可以考虑用整数 所以 名字
 */
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> stu;

bool cmp(int a, int b)
{
  return stu[a] < stu[b];
}
int main()
{
  int n,k,c,tmp;
  char name[5];
  vector<vector<int> > course_stu(2501);
  scanf("%d %d",&n, &k);
  for(int i=0;i<n;++i)
  {
    scanf("%s %d",name, &c);
    stu.push_back(string(name));
    for(int j=0;j<c;++j)
    {
      scanf("%d",&tmp);
      course_stu[tmp].push_back(i);
    }
  }
  for(int i=1;i<=k;++i)
  {
    sort(course_stu[i].begin(),course_stu[i].end(), cmp);
    int size = course_stu[i].size();
    printf("%d %d\n", i, size);
    for(int j = 0;j<size;++j)
    {
      printf("%s\n",stu[course_stu[i][j]].c_str());
    }
  }
  return 0;
}
