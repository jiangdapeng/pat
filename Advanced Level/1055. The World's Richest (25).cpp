/*
 * 题目本身很好理解
 * 就是一个排序
 * 但是最简单的做法会有几个case过不了
 * 通过观察数据，最多只需要输出满足条件的前100位，
 * 因此考虑将先用（age,worth)排序，留下每个年龄上的前100位
 * 然后再用(worth,age,name)排名，每次查询的时候过通过年龄过滤即可
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Peo
{
  char name[10];
  int age;
  int worth;
};

bool cmp(const Peo& a, const Peo& b)
{
  if(a.worth > b.worth) return true;
  if(a.worth < b.worth) return false;
  if(a.age < b.age) return true;
  if(a.age > b.age) return false;
  return strcmp(a.name,b.name) < 0;
}

bool cmp_age(const Peo& a, const Peo& b)
{
  if(a.age < b.age) return true;
  if(a.age > b.age) return false;
  return a.worth > b.worth;
}

Peo a[100000];

int main()
{
  int n,k;
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; ++i)
  {
    scanf("%s %d %d",a[i].name, &a[i].age, &a[i].worth);
  }

  // 去掉 每个年龄上worth排名100之后人
  int pre_age = -1;
  int acount = 0;
  int c = 0;
  sort(a, a+n, cmp_age);
  for(int i=0;i<n;++i)
  {
    if(a[i].age == pre_age)
    {
      if(acount < 100)
      {
        acount++;
        a[c++] = a[i];
      }
    }
    else
    {
      pre_age = a[i].age;
      a[c++] = a[i];
      acount = 1;
    }

  }

  sort(a, a+c, cmp);
  int m, amin, amax;
  for(int j=1; j<= k; ++j)
  {
    printf("Case #%d:\n",j);
    scanf("%d %d %d", &m, &amin, &amax);
    int count = 0;
    for(int i=0; i<c; ++i)
    {
      if(a[i].age >= amin && a[i].age <= amax)
      {
        count++;
        printf("%s %d %d\n", a[i].name, a[i].age, a[i].worth);
      }
      if(count == m) break;
    }
    if(count == 0)
      printf("None\n");
  }
  return 0;
}

