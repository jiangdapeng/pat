#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
const int MAX_SIZE = 10001;

int main()
{
	char s1[MAX_SIZE];
	char s2[MAX_SIZE];
	cin.getline(s1,sizeof(s1));
	cin.getline(s2,sizeof(s2));
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	set<char> schar;
	schar.insert(s2,s2+len2);
	int k=0;
	for(int i=0;i<len1;++i)
	{
		if(schar.find(s1[i])==schar.end())
			s2[k++] = s1[i];
	}
	s2[k] = '\0';
	printf("%s\n",s2);
	return 0;
}