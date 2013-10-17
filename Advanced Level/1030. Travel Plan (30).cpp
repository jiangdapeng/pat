/**
 * 1030. Traval Plan(30) 
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int  MAX_NODE_SIZE = 500;
int road[MAX_NODE_SIZE * MAX_NODE_SIZE];
int costs[MAX_NODE_SIZE * MAX_NODE_SIZE];// cost of each road 
int dist[MAX_NODE_SIZE];
int pre[MAX_NODE_SIZE];
bool visited[MAX_NODE_SIZE];
int count[MAX_NODE_SIZE]; // count shortest path number
int sum_costs[MAX_NODE_SIZE];// count the total cost from start to some city
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
  //cout <<"nearest city:"<<city<<endl;
  return city;
}

void update_neighbor(int k)
{
  // update neighbor city of city k
  for(int j=0;j<n;++j)
  {
    int edge = road[k*n+j];
    int cost = costs[k*n +j]; 
    if(!visited[j] && edge>0)
    {
      if(dist[j] > dist[k] + edge)
      {
        dist[j] = dist[k] + edge;
        pre[j] = k;
        count[j] = count[k];
        sum_costs[j] = sum_costs[k] + cost;
        //cout << "pre["<<j<<"]="<<k<<endl;
      }
      else if(dist[j] == dist[k] + edge)
      {
        // more than one shortest path to city j
        count[j] += count[k];
        // this path cost less
        if(sum_costs[j] >  sum_costs[k] + cost)
        {
          pre[j] = k;
          sum_costs[j] = sum_costs[k] + cost;
        }
      }
    }
  }
}

void print_path(int end)
{
  if(pre[end] >= 0)
  {
    print_path(pre[end]);
    cout << " " << end;
  }
  else
    cout << end ;
}

int main()
{
  int m,start,end;
  cin >> n >> m >> start >> end;
  // init
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

  // input roads
  // distance and cost
  int c1,c2;
  for(int i=0;i<m;++i)
  {
    // dist and cost  between two city
    cin >> c1 >> c2;
    cin >> road[c1*n + c2] >> costs[c1*n + c2];
    road[c2*n + c1] = road[c1*n+c2];
    costs[c2*n + c1] = costs[c1*n+c2];
  }

  // start from start city
  dist[start] = 0;
  pre[start] = -2;
  count[start] = 1;// one shortest path from start to start
  sum_costs[start] = 0;
  while(true)
  {
    int city = nearest_city();
    visited[city] = true;
    if(city == end)
      break;
    update_neighbor(city);
  }
  print_path(end);
  //cout << endl << "paths:"<<count[end]<<endl;
  //cout << "max cost:" << sum_costs[end]<<endl;
  cout << " " <<  dist[end]  << " " << sum_costs[end] << endl;
  return 0;
}
