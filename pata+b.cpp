#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

void format(int  n)
{
  bool neg = false;
  if(n<0)
  {
    neg = true;
    n = -n;
  }
  stack<int> vi;
  do
  {
    vi.push(n%1000);
    n /= 1000;
  }while(n!=0);
  if(neg)
    cout << "-";
  cout << vi.top();
  vi.pop();
  while(!vi.empty())
  {
    int top = vi.top();
    vi.pop();
    printf(",%03d",top);
  }
  cout << endl;
}

int main()
{
  int a,b;
  cin >> a >> b;
  format(a+b);
  return 0;
}
