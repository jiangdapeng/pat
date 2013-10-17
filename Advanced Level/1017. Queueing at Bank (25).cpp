/*

#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,k,i,h,m,s,w,hour;
deque<pair<int,int> > Peo;

int Windows[101];

int cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}

bool has_Windows(int &win_num)
{
    for(int i = 0; i < k; i++)
    {
        if(Windows[i] == 0)
        {
            win_num = i;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> k;
    memset(Windows, 0, sizeof(Windows));
    int peoNum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d",&h,&m,&s,&w);
        if(h >= 17 && m >=0 && s >=0)
        {
            continue;
        }
        hour = h*60*60+m*60+s;
        if(w > 60)  w = 60;
        peoNum++;
        Peo.push_back(make_pair(hour, w*60));
    }

    sort(Peo.begin(), Peo.end(), cmp);

    int time = -1;
    int ans = 0;
    while( !Peo.empty() )
    {
        for(i = 0; i < k; i++)
        {
            if(Windows[i] != 0)
                Windows[i]--;
        }

        int win_num;
        while( !Peo.empty() && has_Windows(win_num) && time >= 8*60*60 && time >= Peo[0].first )
        {
            Windows[win_num] = Peo[0].second;
            ans += time - Peo[0].first;
            Peo.pop_front();
        }
        time++;
    }
    if(!peoNum)
        cout << "0.0" << endl;
    else
        printf("%.1lf\n", (double)ans/(peoNum*60.0));
    return 0;
}

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

struct Customer
{
	int process; // in minutes
	int arrive; // in seconds
};

bool wait_order(const Customer& a, const Customer& b)
{
	return a.arrive < b.arrive;
}

/*

int main()
{
	int n,k;
	int start_time = 8 * 3600;
	int end_time = 17 * 3600;
	cin >> n >> k;
	Customer c;
	vector<Customer> cs;
	int h,m,s;
	for(int i=0;i<n;++i)
	{
		scanf("%d:%d:%d %d",&h,&m,&s,&c.process);
		c.arrive = h * 3600 + m * 60 + s;
		if(c.arrive > end_time) continue;
		c.process = c.process>60?60:c.process; // at most 1 hour
		cs.push_back(c);
	}
	sort(cs.begin(),cs.end(),wait_order);
	// print_cs(cs);
	vector<int> ws(100,start_time); // at most 100 windows
	int total_waiting = 0; // in seconds
	int waiting = 0; // for some customer
	int i=0;
	for(i=0;i<cs.size();++i)
	{
		waiting = 0;
		int min_idx = 0;// peek the quickest window
		for(int j=0;j<k;++j)
		{
			if(ws[j] < cs[i].arrive)
				ws[j] = cs[i].arrive;
			if(ws[j] < ws[min_idx])
				min_idx = j;
		}
		if(ws[min_idx] > end_time)
		{
			waiting = end_time - cs[i].arrive;
			// need to count thoese customer who come after current customer but before end_time
		}
		else
		{
			waiting = ws[min_idx] - cs[i].arrive;
		}
		total_waiting += waiting;
		// cout << "total:" << total_waiting << " waiting:" << waiting << endl;
		ws[min_idx] += cs[i].process * 60; // update window's finish time in seconds
	}
	if(i == 0)
		cout << "0.0" << endl;
	else
		printf("%.1lf\n",total_waiting * 1.0 / 60 / i); // in minutes
	return 0;
}
*/