#include <string>
#include <iostream>
using namespace std;

struct Student
{
  string name;
  string num;
  int grade;
};

int main()
{
  int n;
  cin >> n;
  Student st;
  Student max;
  Student min;
  cin >> st.name >> st.num >> st.grade;
  max = min = st;
  for(int i=1;i<n;++i)
  {
    cin >> st.name >> st.num >> st.grade;
    if(st.grade > max.grade)
      max = st;
    if(st.grade < min.grade)
      min = st;
  }
  cout << max.name << " " << max.num << endl;
  cout << min.name << " " << min.num << endl;
  return 0;
}
