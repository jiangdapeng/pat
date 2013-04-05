/**
 * 1003. Emergency
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int  MAX_NODE_SIZE = 500;
int road[MAX_NODE_SIZE * MAX_NODE_SIZE];
int dist[MAX_NODE_SIZE];
int pre[MAX_NODE_SIZE];
int power[MAX_NODE_SIZE];// person
bool visited[MAX_NODE_SIZE];
int count[MAX_NODE_SIZE]; // count shortest path number
int n;// number of city

int nearest_city()
{
  int i=0;
  for(;i<n;++i)
  {
    if(!visited[i])
    {
      break;
    }
  }
  int city = i;
  for(;i<n;++i)
  {
    if(!visited[i] && dist[i]<= dist[city])
    {
      city = i;
    }
  }
  cout <<"nearest city:"<<city<<endl;
  return city;
}

void update_neighbor(int k)
{
  // update neighbor city of city k
  for(int j=0;j<n;++j)
  {
    int edge = road[k*n+j];
    if(!visited[j] && edge>0)
    {
      if(dist[j] > dist[k] + edge)
      {
        dist[j] = dist[k] + edge;
        pre[j] = k;
        count[j] = count[k];
        cout << "pre["<<j<<"]="<<k<<endl;
      }
      else if(dist[j] == dist[k] + edge)
      {
        // more than one shortest path to city j
        count[j] += count[k];
      }
    }
  }
}

void print_path(int end)
{
  if(pre[end] >= 0)
  {
    print_path(pre[end]);
    cout << "-->" << end;
  }
  else
    cout << end ;
}

int main()
{
  int m,start,end;
  cin >> n >> m >> start >> end;
  for(int i=0;i< n;++i)
  {
    for(int j=0;j<n;++j)
    {
      road[i*n + j] = 0;
    }
    dist[i] = INT_MAX; 
    visited[i] = false;
    pre[i] = -1;
    count[i] = 0;
  }
  for(int i=0;i<n;++i)
  {
    cin >> power[i];
  }
  int c1,c2;
  for(int i=0;i<m;++i)
  {
    // dist between two city
    cin >> c1 >> c2;
    cin >> road[c1*n + c2];
    road[c2*n + c1] = road[c1*n+c2];
  }

  // start from start city
  dist[start] = 0;
  pre[start] = -2;
  count[start] = 1;// one shortest path from start to start
  while(true)
  {
    int city = nearest_city();
    visited[city] = true;
    if(city == end)
      break;
    update_neighbor(city);
  }
  print_path(end);
  cout << endl << "paths:"<<count[end]<<endl;
  return 0;
}
