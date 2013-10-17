#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Lnode
{
	int addr;
	int value;
	int next;
}linkList[100001];

bool cmp(const Lnode& a,const Lnode& b)
{
	return a.value < b.value;
}



int main()
{
	int n,head;
	vector<Lnode> nodes;
	Lnode tmp;
	cin >> n >> head;
	// 边界测试点
	if(head == -1)
	{
		printf("0 -1\n");
		return 0;
	}
	for (int i=0;i<n;++i)
	{
		cin >> tmp.addr >> tmp.value >> tmp.next;
		if (tmp.addr == -1)
		{
			continue;// 过滤掉无用数据，这一点题目并没有说得很明确
		}
		linkList[tmp.addr] = tmp;
	}
	// 只有从Head 开始链表可达的数据是有效数据
	int curAddr = head;
	while (curAddr !=-1)
	{
		nodes.push_back(linkList[curAddr]);
		curAddr = linkList[curAddr].next;
	}
	sort(nodes.begin(),nodes.end(),cmp);
	printf("%d %05d\n",nodes.size(),nodes[0].addr);
	int i;
	for (i=0;i<nodes.size()-1;++i)
	{
		printf("%05d %d %05d\n",nodes[i].addr,nodes[i].value,nodes[i+1].addr);
	}
	printf("%05d %d -1\n",nodes[i].addr,nodes[i].value);
	return 0;
}