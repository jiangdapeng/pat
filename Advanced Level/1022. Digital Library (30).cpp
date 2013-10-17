/*
	有三个simple case 答案错误，搞不懂为什么
	耗时最长的case 都没有问题
	顺便吐槽，测试数据明显有不完善之处
*/
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

const int MAX_SIZE = 10001;
const int TITLE_LEN = 81;
const int KEYWORDS_LEN = 60;

vector<string> split(const char* str,char dem=' ')
{
	int i=0;
	int j=0;
	int len=strlen(str);
	char kw[11];
	vector<string> kws;
	while(i<len)
	{
		while(i<len && str[i]!=dem)
			i++;
		kws.push_back(string(str+j,str+i));
		i++;
		j = i;
	}
	return kws;
}

int main()
{
	int n;
	cin >> n;
	map<string,set<string> > title2book;
	map<string,set<string> > author2book;
	map<string,set<string> > kw2book;
	map<string,set<string> > pub2book;
	map<int,set<string> > year2book;

	char keywords[KEYWORDS_LEN];
	char title[TITLE_LEN];
	char author[TITLE_LEN];
	char pub[TITLE_LEN];
	char id[8];
	int year;
	for(int i=0;i<n;++i)
	{
		scanf("%s\n",id);
		cin.getline(title,TITLE_LEN);
		cin.getline(author,TITLE_LEN);
		cin.getline(keywords,KEYWORDS_LEN);
		cin.getline(pub,TITLE_LEN);
		cin >> year;
		title2book[title].insert(id);
		author2book[author].insert(id);
		pub2book[pub].insert(id);
		year2book[year].insert(id);
		vector<string> kws = split(keywords);
		for(auto it = kws.begin();it!=kws.end();++it)
		{
			kw2book[*it].insert(id);
		}
	}
	// query
	int m;
	cin >> m;
	int type;
	char query[TITLE_LEN];
	set<string> result;
	for(int i=0;i<m;++i)
	{
		scanf("%d: ",&type);
		if(type == 5)
			scanf("%d",&year);
		else
			scanf("%[^\n]",query);
		switch(type)
		{
		case 1:
			// title
			result = title2book[query];
			break;
		case 2:
			// author
			result = author2book[query];
			break;
		case 3:
			// keywords
			result = kw2book[query];
			break;
		case 4:
			// pub
			result = pub2book[query];
			break;
		case 5:
			// year
			result = year2book[year];
			break;
		default:
			break;
		}
		if(type != 5)
			printf("%d: %s\n",type,query);
		else
			printf("%d: %d\n",type,year);
		if(result.empty())
		{
			printf("Not Found\n");
		}
		else
		{
			for(auto it=result.begin();it!=result.end();++it)
			{
				printf("%s\n",(*it).c_str());
			}
		}
	}
	return 0;
}