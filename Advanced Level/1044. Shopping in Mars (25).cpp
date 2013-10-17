#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Section
{
  int i;
  int j;
  int sum;
};

bool my_order(const Section& a, const Section& b)
{
  if(a.sum < b.sum) return true;
  if(a.sum > b.sum) return false;
  else
  {
    return a.i < b.i;
  }
}

int main()
{
  int n,m;
  scanf("%d %d", &n, &m);
  vector<int> diams;
  vector<int> sums;
  int d;
  int i = 0;
  int sum = 0;

  for(int i=0;i<n;++i)
  {
    scanf("%d",&d);
    diams.push_back(d);
    sum += d;
    sums.push_back(sum);
  }
  vector<Section> result;
  Section tmp;
  int min_sum = 100000001;// be carefull!
  int j;
  sum = 0;
  for(i=0; i< n;++i)
  {
    // look back
    if(i > 0 )
    {
      j = j-1;
    }
    else
    {
      j = i;
    }
    while(j < n)
    {
      if(i > 0)
        sum = sums[j] - sums[i-1];
      else
        sum = sums[j];
      //printf("\ti=%d j=%d sum=%d\n",i,j,sum);
      if(sum >=  m)
      {
        if(sum <= min_sum)
        {
          tmp.i = i;
          tmp.j = j;
          tmp.sum = sum;
          if(sum < min_sum)
            result.clear();
          result.push_back(tmp);
          min_sum = sum;
        }
        break;
      }
      j++;
    }
  }
  //sort(result.begin(),result.end(),my_order);
  vector<Section>::iterator it = result.begin();
  min_sum = it->sum;
  for(it=result.begin();it!=result.end();++it)
  {
    if(it->sum > min_sum)
      break;
    printf("%d-%d\n",it->i + 1, it->j + 1);
  }
  return 0;
}
