#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int m,n,k;
	cin >> m >> n >> k;
	for (int i=0;i<k;++i)
	{
		// test sequence
		stack<int> s;
		int cur;
		int j =0;
		int p = 1;
		bool ok = true;
		vector<int> test;
		for (int j=0;j<n;++j)
		{
			cin >> cur;
			test.push_back(cur);
		}
		for (j=0;j<n;++j)
		{
			cur = test[j];
			while ((s.empty() || (s.top() != cur && s.size()<m)) && p <= n)
			{
				s.push(p++);
			}
			if (s.top() == cur)
			{
				s.pop();
			}
			else
			{
				ok = false;
				break;
			}
		}
		if (ok && s.empty())
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}