#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Poly
{
  int exp;
  float coe;
};

vector<Poly> poly_add(const vector<Poly>& p1, const vector<Poly>& p2)
{
  Poly tmp;
  vector<Poly>::const_iterator vi1 = p1.begin();
  vector<Poly>::const_iterator vi2 = p2.begin();
  vector<Poly> result;
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
  return result;
}

vector<Poly> item_prod_poly(const Poly& item, const vector<Poly>& p)
{
  vector<Poly> result;
  vector<Poly>::const_iterator cit = p.begin();
  Poly tmp;
  while(cit != p.end())
  {
    tmp.coe = cit->coe * item.coe;
    if(tmp.coe !=0)
    {
      tmp.exp = cit->exp + item.exp;
      result.push_back(tmp);
    }
    ++cit;
  }// end of while
  return result;// here large copy operation, not good
}

vector<Poly> poly_prod(const vector<Poly>& p1, const vector<Poly>& p2)
{
  Poly tmp;
  vector<Poly>::const_iterator vi1 = p1.begin();
  vector<Poly> result;
  while(vi1 != p1.end())
  {
    vector<Poly> m = item_prod_poly(*vi1,p2);
    result = poly_add(result,m);
    ++vi1;// take care of this when using while
  }// end of while
  return result;
}


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
  // p1 * p1
  vector<Poly> result = poly_prod(p1, p2);
  cout << result.size();
  vector<Poly>::iterator vi1 = result.begin();
  while(vi1 != result.end())
  {
    printf(" %d %.1f",vi1->exp,vi1->coe);
    ++vi1;
  }
  cout << endl;
  return 0;
}
