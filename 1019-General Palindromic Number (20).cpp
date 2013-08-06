#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deci2base(int n, int base)
{
	vector<int> rt;
	do
	{
		rt.push_back(n%base);
		n /= base;
	}while(n!=0);
	return rt;// here rt is reverse order of in base
}

bool is_pal(const vector<int>& seq)
{
	int i=0;
	int j=seq.size()-1;
	for(;i<j;i++,j--)
	{
		if(seq[i] != seq[j]) return false;
	}
	return true;
}

void is_pal(int n, int base)
{
	vector<int> basen = deci2base(n,base);
	bool result = is_pal(basen);
	if(result) cout << "Yes" << endl;
	else cout << "No" << endl;
	for(auto it = basen.rbegin();it!=basen.rend();++it)
	{
		if(it != basen.rbegin()) cout << " ";
		cout << *it;
	}
}

/*

int main()
{
	int n, base;
	cin >> n >> base;
	is_pal(n,base);
	return 0;
}
*/