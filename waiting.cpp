#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

const int MAX_WIN_COUNT = 20;
const int WIN_SIZE = 10;

struct Customer
{
  int id;
  int time;
};

int min(const vector<queue<Customer> > & windows, const vector<int>& wintime,int size)
{
  int minvalue = 10000;
  int tmp = 0;
  for(int i=0;i<size;++i)
  {
    if(windows[i].size() > 0)
    {
      // cout <<"window " << i+1 << " wintime:" << wintime[i]<< " id:" <<  windows[i].front().id << " time:" << windows[i].front().time  << endl;
      tmp = windows[i].front().time + wintime[i];
      if(tmp < minvalue)
        minvalue = tmp;
    }
  }
  return minvalue;
}

void format(int timecost)
{
  int act = 480 + timecost; // from 08:00
  int hour = act / 60;
  int m = act % 60;
  printf("%02d:%02d\n",hour, m);
}


int main()
{
  int n,m,k,q;
  vector<int> custom;// custom's processing time
  int finishtime[1000];
  vector<int> wintime(MAX_WIN_COUNT);// current window time with initial value 0 
  vector<queue<Customer> > windows(MAX_WIN_COUNT);
  cin >> n >> m >> k >> q;
  int c;
  for(int i=0;i<k;++i)
  {
    cin >> c;
    custom.push_back(c);
  }
  int capacity = n * m;
  int num =  k < capacity ? k : capacity;
  
  // init
  Customer cust;
  for(int i=0;i<num;++i)
  {
    // fill window line
    cust.id = i;
    cust.time = custom[i];
    windows[i%n].push(cust);
  }
  // start service
  int serviced =0;
  while(serviced < k)
  {
    // 
    int latest = min(windows,wintime,n);
    // for each window
    for(int i=0;i<n;++i)
    {
      if(windows[i].size() >0 && ((windows[i].front().time + wintime[i]) == latest))
      {
        //one  service finish
        Customer cur = windows[i].front();
        windows[i].pop();
        wintime[i] = latest;
        finishtime[cur.id] = wintime[i];
        serviced++;
        // cout << "window " << i+1 << " customer " << cur.id + 1 << " finished at " << wintime[i]<< endl;
        if(num < k)
        {
          // some customs are waiting out of queue
          Customer tmp;
          tmp.id = num;
          tmp.time = custom[num];
          windows[i].push(tmp);
          ++num;
        }
      }
    }
  }
  int query;
  for(int i=0;i<q;++i)
  {
    cin >> query;
    int idx = query -1;
    if(finishtime[idx]<= 540)
      format(finishtime[idx]);
    else
      cout << "Sorry" << endl;
  }
  return 0;

}
