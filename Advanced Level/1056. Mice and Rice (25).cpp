/*
 * 这道题把我坑死了！
 * 题目意思没看懂啊，有木有
 * 我勒个去。。。。
 * 是我理解能力太差还是还是太奇葩了
 * 第一行两个数字：参赛人数 n（也就是老鼠的个数） 和 分组中的最大人数
 * 第二行的数字表示老鼠的重量，也就是第 i 个参赛人员的老鼠最终的重量就是 w[i]
 * 第三行的数字是初始的小组划分序列 每个数字的意思是 参赛人员的编号
 * 题目意思明白后，思路倒是很简单
 * 就是每次找出分组中的优胜者，进入下一轮比赛
 * 用两个空间的轮换使用就可以解决，大循环结束的条件就是比赛只剩下1个参赛者
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_PROG = 2001;
int a[2][MAX_PROG];
int weight[MAX_PROG];
int grank[MAX_PROG];

int main()
{
  int np,ng;
  scanf("%d %d", &np, &ng);

  for(int i=0;i<np;++i)
  {
    scanf("%d",weight + i);
  }

  for(int i=0;i<np;++i)
  {
    scanf("%d",&a[0][i]);
  }

  int r = 0;
  int cur = 0; // 当前使用的数组
  int rest = np; // 这一轮比赛的人数
  while(rest > 1)
  {
    // 这一轮比赛被淘汰的人的名次也就是
    // 能进入下一轮比赛的人数 + 1
    r = rest/ng + (rest%ng == 0?0:1) + 1;
    int next = 0;
    // 按照小组循环
    for(int i=0;i<rest; i+= ng)
    {
      int max_w = weight[a[cur][i]];
      int max_id = i;
      // 找出小组内的优胜者
      for(int j=i+1;j < i+ng && j < rest;++j)
      {
        if(weight[a[cur][j]] > max_w)
        {
          max_w = weight[a[cur][j]];
          max_id = j;
        }
      }
      a[1-cur][next++] = a[cur][max_id];// max in group

      // 被淘汰的人名次一致
      for(int j=i;j< i+ ng && j < rest; ++j)
      {
        if(j != max_id)
        {
          int pid = a[cur][j];
          grank[pid] = r;
        }
      }
    }
    rest = next;
    cur = 1 - cur;
  }
  grank[a[cur][0]] = 1;
  for(int i=0;i<np;++i)
  {
    printf("%d",grank[i]);
    if(i != np-1)
      printf(" ");
  }
  printf("\n");
  return 0;
}
