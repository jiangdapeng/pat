/*
	保存与原点的距离，最后相减就行了- -
*/
#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

int dist[100001];

int main()
{
	int n,m,tmp;
	cin >> n;
	int total = 0;
	dist[0] = 0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&tmp);
		dist[i] = dist[i-1] + tmp;
		total += tmp;
	}
	scanf("%d",&m);
	int start,end;
	for (int i=0;i<m;++i)
	{
		scanf("%d %d",&start,&end);
		start = min(start,end);
		end = max(start,end);
		int d = dist[end-1] -dist[start-1];
		printf("%d\n",min(d,total-d));
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <map>
//#include <stdio.h>
//
//using namespace std;
//
//
//map<pair<int,int>,int> ds;
//
//int calc_dist(pair<int,int> r)
//{
//	if (ds.find(r) == ds.end())
//	{
//		pair<int,int> left, right;
//		left.first = r.first;
//		left.second = r.first + (r.second-r.first)/2;
//		right.first = left.second;
//		right.second = r.second;
//		ds[r] = calc_dist(left) + calc_dist(right);
//	}
//	return ds[r];
//}
//
//int main()
//{
//	int n,m;
//	cin >> n;
//	int tmp;
//	vector<int> exits;
//	int total = 0;
//	pair<int,int> r;
//	for(int i=0;i<n;++i)
//	{
//		scanf("%d",&tmp);
//		exits.push_back(tmp);
//		total += tmp;
//		r.first = i+1;
//		r.second = i+2;
//		ds[r] = tmp;
//	}
//	cin >> m;
//	int e1,e2;
//	for (int i=0;i<m;++i)
//	{
//		scanf("%d %d",&e1,&e2);
//		if (e1 > e2)
//		{
//			tmp = e1;
//			e1 = e2;
//			e2 = tmp;
//		}
//		r.first = e1;
//		r.second = e2;
//		int dist = calc_dist(r);
//		if (dist*2 < total)
//		{
//			printf("%d\n",dist);
//		}
//		else
//		{
//			printf("%d\n",total-dist);
//		}
//	}
//	return 0;
//}


