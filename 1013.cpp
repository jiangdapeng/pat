/**
 * www.pat.zju.edu.cn
 * 1013 Battle Over Cities
 *
 * */
#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAX_CITY_NO = 1001;

void initCity(vector<int>& city)
{
  for(int i=0;i<city.size();++i)
  {
    city[i] = i;
  }
}

// total n cities, remove city k
int repair(const vector<int>& city, int n, int k)
{
  set<int> sets;
  for(int i=1;i<=n;++i)
  {
    if(i != k)
    {
      //cout << "city[" << i << "]=" <<  city[i] << endl;
      sets.insert(city[i]);
    }
  }
  return sets.size() -1;
}

int main()
{
  int n,m,k;
  vector<int> city(MAX_CITY_NO);
  vector<vector<int> > roads(MAX_CITY_NO);
  cin >> n >> m >> k;
  int c1,c2;
  for(int i=0;i<m;++i)
  {
    cin >> c1 >> c2;
    if(c1 > c2)
    {
      int tmp = c1;
      c1 = c2;
      c2 = tmp;
    }
    roads[c1].push_back(c2);// a direct road between c1 and c2
  }
  vector<int> testPoint;
  for(int i=0;i<k;++i)
  {
    cin >> c1;// remove city c1
    initCity(city);
    for(int j=1; j<= n;++j)
    {
      if(j != c1 )
      {
        // connected cities of j
        for(int c=0;c<roads[j].size();++c)
        {
          if(roads[j][c] == c1)
            continue;
          if(city[roads[j][c]] != roads[j][c])
            city[j] = city[roads[j][c]];
          else
            city[roads[j][c]] = city[j];
        }
      }
    }
    int repairs = repair(city,n,c1);
    cout << repairs << endl;
  }
  return 0;
}
