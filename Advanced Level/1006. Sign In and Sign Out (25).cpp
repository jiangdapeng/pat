#include <vector>
#include <iostream>

using namespace std;

struct Record
{
  string ID;
  string sign_in;
  string sign_out;
};

int main()
{
  int n;
  cin >> n;
  vector<Record> rs;
  Record tmp;
  Record in;
  Record out;
  cin >> tmp.ID >> tmp.sign_in >> tmp.sign_out;
  in = out = tmp;
  for(int i=1;i<n;++i)
  {
    cin >> tmp.ID >> tmp.sign_in >> tmp.sign_out;
    if(in.sign_in.compare(tmp.sign_in) > 0)
    {
      in = tmp;
    }
    if(out.sign_out.compare(tmp.sign_out) < 0)
    {
      out = tmp;
    }
  }
  cout << in.ID<< " " << out.ID<< endl;
  return 0;
}
