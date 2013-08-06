/*
	注意：当某个用户没有合法的话费记录时，他的信息是不需要输出的
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

struct Record
{
	string name;
	string time;
	string on_off;
	int month,day,hour,min;
};

void split_time(const string& time, int & month,int & day,int & hour, int& min)
{
	// time's format mm:dd:hh:mm
	month = time[1]-'0' + (time[0]- '0')*10;
	day = time[4]-'0' + (time[3]- '0')*10;
	hour = time[7]-'0' + (time[6]- '0')*10;
	min = time[10]-'0' + (time[9]- '0')*10;
}

bool bill_order(const Record& a, const Record& b)
{
	if(a.name < b.name) return true;
	if(a.name == b.name) return a.time < b.time;
	return false;
}

void print_rs(const vector<Record>& rs)
{
	cout << "start" << endl;
	for(auto it=rs.begin();it!=rs.end();++it)
	{
		cout << it->name << " " << it->time << " " << it->on_off << endl;
		cout << it->month << ":" << it->day << ":" << it->hour << ":" << it->min << endl;
	}
	cout << "end" << endl;
}

/*

int main()
{
	vector<Record> rs;
	Record tmp;
	int price[24];
	// input price 
	int day_cost = 0;
	for(int i=0;i<24;++i)
	{
		cin >> price[i];
		day_cost += price[i];
	}
	day_cost *= 60; // cost of a whole day
	int n;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> tmp.name >> tmp.time >> tmp.on_off;
		split_time(tmp.time,tmp.month,tmp.day,tmp.hour,tmp.min);
		rs.push_back(tmp);
	}
	// sort in name alpha order and time chron order
	sort(rs.begin(),rs.end(),bill_order);

	string lastname;
	int total_cost =  0;// money in cents
	int total_ms = 0; // total minites
	bool begin = false; // a pair begin found
	bool end = false; // a pair end found
	int on_idx = 0; // 
	int off_idx = 0;
	for(int i=0;i<rs.size();)
	{
		total_cost = 0;
		total_ms = 0;
		begin = end = false;
		lastname = rs[i].name;
		// deal with one user
		bool first = true; // there is at least one legal pair for current user
		while(i<rs.size() && lastname == rs[i].name)
		{
			if(begin)
			{
				if(rs[i].on_off == "on-line")
				{
					on_idx = i; // update on_idx
				}
				else
				{
					end = true;
					off_idx = i; // a pair found
				}
			}
			else
			{
				if(rs[i].on_off == "on-line")
				{
					begin = true;
					on_idx = i; // a pair begin
				}
			}

			if(end)
			{
				// count this pair's cost
				int cost = 0;
				int ms = 0;
				int dd = rs[off_idx].day - rs[on_idx].day;
				int dh = rs[off_idx].hour - rs[on_idx].hour;
				int dm = rs[off_idx].min - rs[on_idx].min;
				ms = dd * 24 * 60 + dh * 60 + dm;  // count time cost
				int cof = 0;
				for(int j=0;j<rs[off_idx].hour;++j)
					cof += price[j] * 60;
				cof += price[rs[off_idx].hour] * rs[off_idx].min; // 

				int con = 0;
				for(int j=0;j<rs[on_idx].hour;++j)
					con += price[j] * 60;
				con += price[rs[on_idx].hour] * rs[on_idx].min;
				cost = day_cost * dd + cof - con; //

				total_cost += cost;
				total_ms += ms;

				if(first)
				{
					printf("%s %02d\n",lastname.c_str(),rs[i].month);
					first = false;
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",rs[on_idx].day,rs[on_idx].hour,rs[on_idx].min,rs[off_idx].day,rs[off_idx].hour,rs[off_idx].min,ms,cost*1.0/100);

				// update flag to look for next pair
				begin = false;
				end = false;
			}
			i++;
		}//end-of-while
		if(!first) printf("Total amount: $%.2f\n",total_cost*1.0/100);
	}
	return 0;
}

*/