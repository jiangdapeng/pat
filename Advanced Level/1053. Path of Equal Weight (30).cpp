#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

const int MAX__TREE_SIZE = 100;

struct Node 
{
	int id;
	int w;
	// 注意：这里的比较决定了确定元素唯一性的依据
	// 如果只比较 w ，那么会造成set里面 w 相同的node 只会保留一个
	// 这个隐含的问题害我调试好久！！！
	bool operator ()(const Node& a, const Node& b)
	{
		if (a.w > b.w) return true;
		if (a.w < b.w) return false;
		return a.id < b.id;
	}
};

vector<int> seq;
vector<int> weights(MAX__TREE_SIZE);
vector<set<Node,Node> > tree(MAX__TREE_SIZE);

int n,m;
int path_len;

void visit_tree(int node,vector<int>& seq, int sum)
{
	/*
	int len = seq.size();
	for (int i=0;i<2*len;++i)
	{
		cout << "-";
	}
	cout << "node=" << node  << " w=" << weights[node] << " c=" << tree[node].size()<< endl;
	cout << "sum=" << sum << endl;
	cout << endl;*/
	int newsum = sum+weights[node];
	if (newsum > path_len) return;
	if (newsum == path_len)
	{
		if (tree[node].empty())
		{
			// it is leaf node
			bool first = true;
			for (auto it=seq.begin();it!=seq.end();++it)
			{
				if (first)
				{
					cout << *it;
					first = false;
				}
				else
					cout << " " << *it;
			}
			if(first) cout << weights[node];
			else cout << " " << weights[node];
			cout << endl;
		}
		else return;
	}
	else
	{
		// go deeper
		sum = newsum;
		seq.push_back(weights[node]);
		for (auto c=tree[node].begin();c!=tree[node].end();++c)
		{
			visit_tree(c->id,seq,sum);
		}
		seq.pop_back();
	}
}


int main()
{
	cin >> n >> m >> path_len;
	for (int i=0;i<n;++i)
	{
		cin >> weights[i];
	}
	int k,child,id;
	Node node;
	for (int i=0;i<m;++i)
	{
		cin >> id >> k;
		//cout << "id=" << id << " k=" <<k <<endl;
		for (int j=0;j<k;++j)
		{
			cin >> child;
			node.id = child;
			node.w = weights[node.id];
			tree[id].insert(node);
		}
	}
	// cout << "node=17 c=" << tree[17].size()<<endl;
	visit_tree(0,seq,0);
	return 0;
}