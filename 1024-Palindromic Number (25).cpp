/*
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAX_LEN = 1001;

char reverse_n[MAX_LEN];
char number[MAX_LEN];

void reverse_str(char* n, int len)
{
	char c = 0;
	for(int i=0,j=len-1;i<j;++i,--j)
	{
		c = n[i];
		n[i] = n[j];
		n[j] = c;
	}
}

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

bool find_pp(char* num, int len, int k,int& step)
{
	int st = 0;
	bool rt = false;
	reverse_str(num, reverse_n, len);
	if(strcmp(num, reverse_n) == 0)
	{
		rt = true;
	}
	else
	{
		while(st < k)
		{
			st++;
			reverse_str(num, reverse_n,strlen(num));
			add_str(num,reverse_n,num);

			reverse_str(num, reverse_n, strlen(num));
			if(strcmp(num,reverse_n) == 0)
			{
				rt = true;
				break;
			}
		}
	}
	step = st;
	return rt;
}

*/

/*

int main()
{
	long long n;
	int k;
	int step = 0;
	scanf("%s %d",number,&k);
	bool rt = find_pp(number,strlen(number),k,step);
	printf("%s\n%d\n",number,step);
	return 0;
}

*/