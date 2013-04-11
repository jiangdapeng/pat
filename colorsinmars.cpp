#include <iostream>
#include <stack>
#include <string>

using namespace std;

char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
char result[10];// attention! when using globel variable 
char* radix_transform(int n)
{
  stack<char> tmp;
  int digit;
  do
  {
    digit = n % 13;
    n /= 13;
    tmp.push(digits[digit]);
  }while(n != 0);

  int i=0;
  if(tmp.size()<2)
  {
    result[i++] = '0';
  }
  while(!tmp.empty())
  {
    result[i++] = tmp.top();
    tmp.pop();
  }
  result[i] = '\0';
  return result;
}

int main()
{
  int r,g,b;
  cin >> r >> g >> b;
  cout << "#" ;
  cout << radix_transform(r) ;
  cout << radix_transform(g) ;
  cout << radix_transform(b)<< endl;
  return 0;
}
