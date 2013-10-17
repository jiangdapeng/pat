/*
	˼·��
		��union-find�ж� ͼ�Ƿ���ͨ
		1. ��ȡһ����x��ʼ��BFS�������ҵ���Զ�ĵ�y����Զ�ľ���d1
			���˱��������о���Ϊ d1�ĵ㶼�Ƿ���Ҫ��ĵ�
		2. ��y��ʼ��BFS�������ҵ���Զ�ĵ�z���Լ���Զ�ľ���d2
			���˱��������о���Ϊd2�ĵ㶼�Ƿ���Ҫ��ĵ�
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10005;
vector<int> sets(MAX_SIZE,-1);
vector<vector<int> > graph(MAX_SIZE);
vector<int> dist(MAX_SIZE,0);
vector<bool> visit(MAX_SIZE,false); // if node is visited

int find(int node)
{
	while(sets[node] !=-1)
		node = sets[node];
	return node;
	/*int p = sets[node];
	if(p == -1)
		return node;
	else
		return sets[node] = find(sets[node]);*/
}

void union_sets(int node1,int node2)
{
	int s1 = find(node1);
	int s2 = find(node2);
	if(s1 != s2)
		sets[node2] = s1;
}

int count_tree(const vector<int>& sets,int n)
{
	int count = 0;
	for(int i=1;i<=n;++i)
	{
		if(sets[i] == -1)
			count ++;
	}
	return count;
}

pair<int,int> bfs(const vector<vector<int> >& graph, int start)
{
	dist.assign(MAX_SIZE,0);
	visit.assign(MAX_SIZE,false);
	deque<int> nodes;
	nodes.push_back(start);// 
	int curnode = 0;
	int max_dist = 0;
	int max_node = start;
	while(!nodes.empty())
	{
		curnode = nodes.front();
		nodes.pop_front();
		visit[curnode] = true;
		for(auto it=graph[curnode].begin();it!=graph[curnode].end();++it)
		{
			// for_each adjacents of curnode
			if(visit[*it])
				continue;

			nodes.push_back(*it);
			dist[*it] = dist[curnode] + 1;
			if(dist[*it] > max_dist)
			{
				max_dist = dist[*it];
				max_node = *it;
			}
		}
	}
	return pair<int,int>(max_dist,max_node);
}

int main()
{
	int n;
	cin >> n;
	int node1,node2;
	for(int i=0;i<n-1;++i)
	{
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
		union_sets(node1,node2);
	}

	int count = count_tree(sets,n);
	if(count > 1)
	{
		cout << "Error: " << count << " components" << endl;
		return 0;
	}

	pair<int,int> max1 = bfs(graph,node1);

	set<int> all;
	for(int i=1;i<=n;++i)
	{
		if(dist[i] == max1.first)
			all.insert(i);
	}
	pair<int,int> max2 = bfs(graph,max1.second);
	for(int i=1;i<=n;++i)
	{
		if(dist[i] == max2.first)
			all.insert(i);
	}

	for(auto it=all.begin();it!=all.end();++it)
	{
		cout << *it << endl;
	}
	return 0;
}