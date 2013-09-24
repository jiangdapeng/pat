/*
 * @author: asuwill
 * key point: 每次停靠在某个加油站，需要找目前所能到达的最远距离内 
 * 第一个价格比当前加油站便宜（或者相等）的加油站作为下一个停靠的加油站
 * 如果不存在，则前往下一个加油站
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_STATIONS = 500;

struct Station
{
  double price;
  double dist;
}ss[MAX_STATIONS];

bool dist_order(const Station& a, const Station& b)
{
  return a.dist < b.dist;
}

int main()
{
  double C, D, unit_d;
  int n;
  int cur_st;
  int next_st;
  double cost = 0;
  double dist = 0;
  double m_dist = 0;
  double gas = 0;
  double gas_need = 0;
  double gas_fill = 0;
  scanf("%lf %lf %lf %d",&C, &D, &unit_d, &n);
  for(int i=0;i<n;++i)
  {
    scanf("%lf %lf",&ss[i].price, &ss[i].dist);
  }
  sort(ss, ss+n, dist_order);
  if(n > 0 && ss[0].dist > 0)
  {
    printf("The maximum travel distance = 0.00\n");
    return 0;
  }
  double tank_dist = C * unit_d;
  cur_st = next_st = 0;
  bool find = false;
  bool done = false;
  while(cur_st < n)
  {
    find = false;
    m_dist = min(ss[cur_st].dist + tank_dist, D);
    next_st = cur_st + 1;
    // look for the first station whose price is less or equal to current price
    while(next_st < n && ss[next_st].dist <= m_dist)
    {
      if(ss[next_st].price <= ss[cur_st].price)
      {
        find = true;
        break;
      }
      next_st++;
    }
    if(find)
    {
      // go to next_st with min gas
      gas_need = (ss[next_st].dist - ss[cur_st].dist) / unit_d;
      if(gas < gas_need)
      {
        gas_fill = gas_need - gas;
        gas = 0;
      }
      else
      {
        gas_fill = 0;
        gas = gas - gas_need;
      }
      cost += gas_fill * ss[cur_st].price;
      dist = ss[next_st].dist;
      cur_st = next_st;
    }
    else
    {
      // 
      if(m_dist >= D)
      {
        // go to destination
        gas_need = (D - ss[cur_st].dist) / unit_d;
        if(gas < gas_need)
        {
          gas_fill = gas_need - gas;
          gas = 0;
        }
        else
        {
          gas_fill = 0;
          gas = gas - gas_need;
        }
        cost += gas_fill * ss[cur_st].price;
        dist = D;
        done = true;
        break;
      }
      else
      {
        if(cur_st == n-1 || ss[cur_st+1].dist > m_dist)
        {
          // can't reach destination and next Station
          dist = m_dist;
          break;
        }
        else
        {
          // go to cur_st + 1
          next_st = cur_st + 1;
          gas_need = (ss[next_st].dist - ss[cur_st].dist) / unit_d;
          gas_fill = C - gas;
          gas = C - gas_need;
          cost += gas_fill * ss[cur_st].price;
          dist = ss[next_st].dist;
          cur_st = next_st;
        }
      }
    }
  }
  if(done)
  {
    printf("%.2lf\n",cost);
  }
  else
  {
    printf("The maximum travel distance = %.2lf\n", dist);
  }
  return 0;
}
