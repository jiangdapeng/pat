/*
 * 用 dynamic programming
 * 一个背包问题
 * 状态转移方程:
 * f[i][v] = max{ f[i-1][v], f[i-1][v - c[i]] + w[i]}
 * f[i][v] 表示 使用前 i 个硬币 所能凑成的小于等于需要付钱数目的最大值
 * that is to say:
 *  1. whether to use the i th coin
 */
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_W = 201;
const int MAX_COINS = 10001;
bool has[MAX_COINS][MAX_W];
int coins[MAX_COINS] = {0};

/*
 * 使用二维数组
 * int sum[MAX_COINS][MAX_W];
 */

// 节省空间
int sum[MAX_W];

bool gt(const int a, const int b)
{
  return a > b;
}

int main()
{
  int n,W;
  scanf("%d %d", &n, &W);
  for(int i=1;i<=n;++i)
  {
    scanf("%d",coins + i);
  }

  sort(coins+1,coins + n + 1,gt);

  /*
   * 使用二维数组
  for(int i=0;i<=MAX_W;++i)
  {
    sum[0][i] = 0;
  }

  // pack bag problem
  for(int i=1;i <=n; ++i)
  {
    for(int v = coins[i]; v <= W; ++v)
    {
      if(sum[i-1][v-coins[i]] + coins[i] >= sum[i-1][v])
      {
        sum[i][v] = sum[i-1][v-coins[i]] + coins[i];
        has[i][v] =  true;
      }
      else
      {
        sum[i][v] = sum[i-1][v];
        has[i][v] = false;
      }
    }
  }
  */
  // find coins sequence

  // initialize
  for(int i=0;i<=MAX_W; ++i)
  {
    sum[i] = 0;
  }

  for(int i=1;i <=n; ++i)
  {
    for(int v = W; v >= coins[i]; --v)
    {
      if(sum[v-coins[i]] + coins[i] >= sum[v])
      {
        sum[v] = sum[v-coins[i]] + coins[i];
        has[i][v] =  true;
      }
      else
      {
        has[i][v] = false;
      }
    }
  }

  int k = n;
  int s = W;
  if(sum[s]!=W)
  {
    // no solution
    printf("No Solution\n");
    return 0;
  }

  vector<int> result;
  while(k > 0)
  {
    if(has[k][s])
    {
      result.push_back(coins[k]);
      s -= coins[k];
    }
    --k;
  }
  printf("%d", result[0]);
  for(int i=1;i<result.size(); ++i)
  {
    printf(" %d",result[i]);
  }
  printf("\n");
  return 0;
}
