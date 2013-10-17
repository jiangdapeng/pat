#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mg(int n1, int n2)
{
  return n1 > n2;
}

int main()
{
  vector<int> coup;
  vector<int> coun;
  vector<int> prodp;
  vector<int> prodn;
  int nc,np;
  long long money = 0;
  cin >> nc;
  int tmp;
  for(int i=0;i<nc;++i)
  {
    cin >> tmp;
    if(tmp >=0)
      coup.push_back(tmp);
    else
      coun.push_back(-tmp);
  }

  cin >> np;
  for(int i=0;i<np;++i)
  {
    cin >> tmp;
    if(tmp >=0)
      prodp.push_back(tmp);
    else
      prodn.push_back(-tmp);
  }

  sort(coup.begin(),coup.end(), mg);
  sort(coun.begin(),coun.end(), mg);
  sort(prodp.begin(),prodp.end(), mg);
  sort(prodn.begin(),prodn.end(), mg);
  
  int sizecp = coup.size();
  int sizecn = coun.size();
  int sizepp = prodp.size();
  int sizepn = prodn.size();
  int sizep = sizecp > sizepp? sizepp:sizecp;
  int sizen = sizecn > sizepn? sizepn:sizecn;
  int p1 = 0;
  for(;p1<sizep;++p1)
  {
    money += coup[p1] * prodp[p1];
  }
  for(p1=0;p1<sizen;++p1)
  {
    money += coun[p1] * prodn[p1];
  }

  cout << money << endl;

  return 0;
}
