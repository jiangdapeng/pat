/*
	remember to deal with input 1
*/
#include <iostream>
#include <vector>
//#include <math.h>

using namespace std;

/*
bool isprime(long n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	int  target = (int )sqrt((double)n);
	for(int  i=2;i<=target;++i)
	{
		if(n % i ==0) return false;
	}
	return true;
}
*/

struct Factor
{
	int  base;
	int  coe;
};

/*
int  main()
{
	int n,bakn;
	vector<Factor> result;
	cin >> bakn;
	n = bakn;
	int  count =0;
	int  i = 2;
	Factor tmp;
	while(i <= n)
	{
		count = 0;
		while(n % i == 0)
		{
			count ++;
			n /= i;
		}
		if(count > 0)
		{
			tmp.base = i;
			tmp.coe = count;
			result.push_back(tmp);
		}
		i++;
	}
	cout << bakn << "=";
	for(auto it = result.begin();it != result.end(); ++it)
	{
		if(it != result.begin())
			cout << "*" ;
		if(it->coe == 1)
		{
			cout << it->base;
		}
		else
		{
			cout << it->base << "^" << it->coe;
		}
	}
	if(result.size() ==0)
		cout << bakn;
	cout << endl;
	return 0;
}
*/