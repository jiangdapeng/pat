#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Poly
{
  int exp;
  float coe;
};

int main()
{
  vector<Poly> p1;
  vector<Poly> p2;
  int k1,k2;
  Poly tmp;
  // read line 1
  cin >> k1;
  for(int i=0;i<k1;++i)
  {
    cin >> tmp.exp >> tmp.coe;
    p1.push_back(tmp);
  }
  // read line 2
  cin >> k2;
  for(int i=0;i<k2;++i)
  {
    cin >> tmp.exp >> tmp.coe;
    p2.push_back(tmp);
  }
  // p1+p1
  vector<Poly> result;
  vector<Poly>::iterator vi1 = p1.begin();
  vector<Poly>::iterator vi2 = p2.begin();
  while((vi1 != p1.end()) && (vi2!= p2.end()))
  {
    if(vi1->exp == vi2->exp)
    {
      tmp.exp = vi1->exp;
      tmp.coe = vi1->coe + vi2->coe;
      if(tmp.coe !=0)
        result.push_back(tmp);
      ++vi1;
      ++vi2;
    }
    else if(vi1->exp > vi2->exp)
    {
      result.push_back(*vi1);
      ++vi1;
    }
    else
    {
      result.push_back(*vi2);
      ++vi2;
    }
  }
  while(vi1 != p1.end())
  {
    result.push_back(*vi1);
    ++vi1;
  }
  while(vi2 != p2.end())
  {
    result.push_back(*vi2);
    ++vi2;
  }
  cout << result.size();
  vi1 = result.begin();
  while(vi1 != result.end())
  {
    printf(" %d %.1f",vi1->exp,vi1->coe);
    ++vi1;
  }
  cout << endl;
  return 0;
}
