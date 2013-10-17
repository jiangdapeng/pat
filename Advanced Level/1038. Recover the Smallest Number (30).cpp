/*
	注意处理 全部是0的情况
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool seg_cmp(const string& a,const string& b)
{
	if(a == b) return false;
	int len1 = a.length();
	int len2 = b.length();
	int i,j;
	i = j =0;
	while(i < len1 && j < len2 && a[i]==b[j])
	{
		i++;
		j++;
	}
	if (i==len1)
	{
		// a=32
		// b=321 or b=324
		return a < b.substr(j,len2-j);
	}
	if (j == len2)
	{
		// a=321 or a=324
		// b= 32
		return a.substr(i,len1-i) < b;
	}
	return a[i] < b[j];
}

int main()
{
	int n;
	cin >> n;
	vector<string> segs;
	string seg;
	for (int i=0;i<n;++i)
	{
		cin >> seg;
		segs.push_back(seg);
	}
	sort(segs.begin(),segs.end(),seg_cmp);
	bool fnzero = false; // first none zero
	for(auto it=segs.begin();it!=segs.end();++it)
	{
		if (!fnzero)
		{
			int i=0;
			while (i < it->length() && (*it)[i] == '0')
			{
				i++;
			}
			if (i<it->length())
			{
				fnzero = true;
				cout << (*it).substr(i,it->length()-i);
			}
		}
		else
			cout << *it;
	}
	if (!fnzero)
	{
		cout << "0"; // all segments are "0...0"
	}
	cout << endl;
	return 0;
}