/*
	ones[n] = m  (n has k-1 digits)
	a > 1
		ones[an] = (a) * ones[10^(k-1)-1] + ones[n] + 10^(k-1)
	a = 1
		ones[an] = (a) * ones[10^(k-1)-1] + ones[n] + n+1
*/


// code from http://www.cnblogs.com/morgan-yuan/archive/2013/03/08/2950687.html
#include <stdio.h>

int main(){
    int d;
    scanf("%d",&d);
    int x=1;
    int total=0;
    while(d/x!=0){
        int right = d%x;
        int left = d/(x*10);
        int current = (d/x)%10;
        if(current==0) 
            total +=left*x;
        else if(current==1)
            total += left*x+right+1;
        else
            total += (left+1)*x;
        x = x*10;
    }
    printf("%d\n",total);
    return 0;
}



/*

// my idea: not correct!


#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	map<int,int> ones;
	ones[0] = 0;
	for(int i=1;i<10;++i)
		ones[i] = 1;
	for(int i=100;i<1000000000;i=i*10)
	{
		ones[i-1] = 10 * ones[i/10-1] + i/10;
	}
	int n;
	cin >> n;
	int count = 0;
	int k = 10;
	int r = 0;
	int prer = 0;
	int bak = n;
	do
	{
		r = bak % k;
		prer = r %(k/10);
		int d = r/(k/10);
		if(r > 0)
		{
			if(d ==1)
				ones[r] = d * ones[k/10 -1] + ones[prer] + prer+1;
			else
				ones[r] = d * ones[k/10 -1] + ones[prer] + k/10 ;
			//cout << "ones[" << r << "]=" << ones[r] << endl; 
		}

		k *= 10;
		n /= 10;
	}while(n!=0);
	cout << ones[bak] << endl;
	return 0;
}

*/