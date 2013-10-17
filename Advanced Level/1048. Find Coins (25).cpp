#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> coins;
	int tmp;
	for (int i=0;i<n;++i)
	{
		cin >> tmp;
		coins.push_back(tmp);
	}
	sort(coins.begin(),coins.end());// increasing order
	int i = 0;
	int j = coins.size()-1;
	bool found = false;
	while (i < j)
	{
		int sum = coins[i] + coins[j];
		if (sum == m)
		{
			found = true;
			break;
		}
		else if (sum < m)
		{
			i++;
		}
		else
			j--;
	}
	if (found)
	{
		cout << coins[i] << " " << coins[j] << endl;
	}
	else
	{
		cout << "No Solution" << endl;
	}
	return 0;
}