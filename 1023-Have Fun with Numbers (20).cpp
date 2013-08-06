#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <stdio.h>
//#include <climits>

using namespace std;

const int MAX_LEN = 25;

void reverse_str(char* src, char * dest, int len)
{
	for(int i=len-1;i>=0;--i)
	{
		dest[len-1-i] = src[i];
	}
	dest[len] = 0;
}


void add_str(const char* a,const char* b,char* out)
{
	char result[MAX_LEN];
	int len1 = strlen(a);
	int len2 = strlen(b);
	int k =0;
	int c = 0;
	int tmp = 0;
	int i = len1 -1;
	int j = len2 - 1;
	for(;i>=0 && j>=0;--i,--j)
	{
		tmp = c+a[i] - '0' + b[j] - '0';
		result[k++] = tmp % 10 + '0';
		c = tmp / 10;
	}
	while(i>=0)
	{
		tmp = c + a[i--] - '0';
		result[k++] = tmp % 10 + '0';
		c = tmp /10;
	}
	while(j>=0)
	{
		tmp = c + a[j--] - '0';
		result[k++] = tmp % 10 + '0';
		c = tmp /10;
	}
	if(c != 0) result[k++] = c + '0';
	result[k] = 0;
	reverse_str(result,out, k);
}

bool is_permutation(const char* a, const char* b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);

	char tmp1[MAX_LEN];
	char tmp2[MAX_LEN];
	strcpy(tmp1,a);
	strcpy(tmp2,b);
	sort(tmp1,tmp1+len1);
	sort(tmp2,tmp2+len2);
	return strcmp(tmp1,tmp2) == 0;
}


int main()
{
	char n[MAX_LEN];
	char dn[MAX_LEN];
	scanf("%s",n);
	add_str(n,n,dn);
	if(is_permutation(n,dn))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	printf("%s\n",dn);
	return 0;
}