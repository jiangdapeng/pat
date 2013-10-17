/*
	这道题也是坑爹，用cin cout会超时
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

struct Student
{
	char id[7];
	char name[9];
	int grade;
};

bool cmp_id(const Student& a,const Student& b)
{
	return strcmp(a.id , b.id) < 0;
}

bool cmp_name(const Student& a,const Student& b)
{
	if(strcmp(a.name, b.name) < 0) return true;
	if(strcmp(a.name, b.name) ==0)
	{
		return strcmp(a.id , b.id) < 0;
	}
	return false;
}

bool cmp_grade(const Student& a,const Student& b)
{
	if(a.grade < b.grade) return true;
	if(a.grade == b.grade) return strcmp(a.id , b.id) < 0;
	return false;
}

int main()
{
	int n,c;
	cin >> n >> c;
	vector<Student> stu;
	Student s;
	for(int i=0;i<n;++i)
	{
		scanf("%s %s %d",s.id,s.name,&s.grade);
		stu.push_back(s);
	}
	if(c == 1)
		sort(stu.begin(),stu.end(),cmp_id);
	else if(c == 2)
		sort(stu.begin(),stu.end(),cmp_name);
	else
		sort(stu.begin(),stu.end(),cmp_grade);
	for(auto it=stu.begin();it!=stu.end();++it)
	{
		printf("%s %s %d\n",it->id,it->name,it->grade);
	}
	return 0;
}