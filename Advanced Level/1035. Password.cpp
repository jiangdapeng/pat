#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

map<char,char>replace;
const int MAX_SIZE = 12;

bool change(char* pwd)
{
	int i=0;
	bool bChanged = false;
	while(pwd[i] != '\0')
	{
		if(replace.find(pwd[i]) != replace.end())
		{
			pwd[i] = replace[pwd[i]];
			bChanged = true;
		}
		i++;
	}
	return bChanged;
}

struct User
{
	char name[MAX_SIZE];
	char pwd[MAX_SIZE];
};

int main()
{
	replace['1'] = '@';
	replace['0'] = '%';
	replace['l'] = 'L';
	replace['O'] = 'o';
	vector<User> us;
	User u;
	int n;
	cin >> n;
	bool bcd = false;

	for(int i=0;i<n;++i)
	{
		scanf("%s %s",u.name,u.pwd);
		if(change(u.pwd))
			us.push_back(u);
	}
	if(us.size() == 0)
	{
		if(n > 1)
			printf("There are %d accounts and no account is modified\n",n);
		else
			printf("There is 1 account and no account is modified");
	}
	else
	{
		cout << us.size() << endl;
		for(auto it=us.begin();it!=us.end();++it)
		{
			printf("%s %s\n",it->name,it->pwd);
		}
	}
	return 0;
}