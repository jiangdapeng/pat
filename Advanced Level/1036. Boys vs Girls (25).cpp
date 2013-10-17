/**
 * 1036 Boys vs girls
 * */

#include <iostream>
#include <string>

using namespace std;

struct Record
{
  string name;
  string sex;
  string id;
  int grade;
};

int main()
{
  bool foundM = false;
  bool foundF = false;

  Record male;
  male.sex = "M";
  male.grade = 101;

  Record female;
  female.sex = "F";
  female.grade = -1;

  Record tmp;

  int n = 0;
  cin >> n;
  for(int i=0;i<n;++i)
  {
    cin >> tmp.name >> tmp.sex >> tmp.id >> tmp.grade;
    if(tmp.sex == "M")
    {
      foundM = true;
      if(tmp.grade < male.grade)
        male = tmp;
    }
    else
    {
      foundF = true;
      if(tmp.grade > female.grade)
        female = tmp;
    }
  }

  if(!foundF)
  {
    cout << "Absent" << endl;
  }
  else
  {
    cout << female.name << " " << female.id << endl; 
  }
  
  if(!foundM)
  {
    cout << "Absent" << endl;
  }
  else
  {
    cout << male.name << " " << male.id << endl; 
  }

  if(!foundM || !foundF)
  {
    cout << "NA" << endl;
  }
  else
  {
    cout << female.grade - male.grade << endl;
  }

  return 0;
}
