#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int n,m,tmp,mul;
	map<int,int> count;
	scanf("%d %d",&m,&n);
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			scanf("%d",&tmp);
			count[tmp] += 1;
		}
	}
	mul = m * n;
	for (auto it=count.begin();it!=count.end();++it)
	{
		if (it->second > mul/2)
		{
			printf("%d\n",it->first);
		}
	}
	return 0;
}