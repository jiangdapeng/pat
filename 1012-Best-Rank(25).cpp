/*

注意：当有 并列分数的时候要取最小的名次
如：a b c的数学分数分别是 99 98 98
那么：a b c的数学最佳排名分别是：1 2 2
*/


/*

// code from github

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu
{
    string ID;
    int C,M,E,A;
}tmp;

int cmpC(const stu &a, const stu &b)
{
    return a.C > b.C;
}

int cmpM(const stu &a, const stu &b)
{
    return a.M > b.M;
}

int cmpE(const stu &a, const stu &b)
{
    return a.E > b.E;
}

int cmpA(const stu &a, const stu &b)
{
    return a.A > b.A;
}

vector<stu> rankC,rankM,rankE,rankA;

void query(string ID)
{
    string from = "";
    int bestRank = 50000, i;
    for(i = 0; i < rankA.size(); i++)
    {
        if(ID == rankA[i].ID)
        {
            int curGrade = rankA[i].A;
            while(curGrade == rankA[i].A)
            {
                i--; // 分数相同 并列名次
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "A";
            }
            break;
        }
    }
    for(i = 0; i < rankC.size(); i++)
    {
        if(ID == rankC[i].ID)
        {
            int curGrade = rankC[i].C;
            while(curGrade == rankC[i].C)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "C";
            }
            break;
        }
    }
    for(i = 0; i < rankM.size(); i++)
    {
        if(ID == rankM[i].ID)
        {
            int curGrade = rankM[i].M;
            while(curGrade == rankM[i].M)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "M";
            }
            break;
        }
    }
    for(i = 0; i < rankE.size(); i++)
    {
        if(ID == rankE[i].ID)
        {
            int curGrade = rankE[i].E;
            while(curGrade == rankE[i].E)
            {
                i--;
            }
            if(i+2 < bestRank)
            {
                bestRank = i+2;
                from = "E";
            }
            break;
        }
    }

    if(bestRank == 50000)  cout << "N/A" << endl;
    else                cout << bestRank << " " << from << endl;
}

int main()
{
    int n,k,i;
    while(cin >> n >> k)
    {
        rankC.clear();
        rankM.clear();
        rankE.clear();
        rankA.clear();
        for(i = 0; i < n; i++)
        {
            cin >> tmp.ID >> tmp.C >> tmp.M >> tmp.E;
            tmp.A = (tmp.C + tmp.M + tmp.E)/3;
            rankC.push_back(tmp);
            rankM.push_back(tmp);
            rankE.push_back(tmp);
            rankA.push_back(tmp);
        }
        stable_sort(rankC.begin(), rankC.end(), cmpC);
        stable_sort(rankM.begin(), rankM.end(), cmpM);
        stable_sort(rankE.begin(), rankE.end(), cmpE);
        stable_sort(rankA.begin(), rankA.end(), cmpA);

        string queryID;
        for(i = 0; i < k; i++)
        {
            cin >> queryID;
            query(queryID);
        }
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Student
{
  string no;// student number
  int c;// c programming
  int m;// math
  int e;// english
  int a;// average
};

bool greatera(const Student& s1, const Student& s2)
{
  return s1.a > s2.a;
}

bool greaterc(const Student& s1, const Student& s2)
{
  return s1.c > s2.c;
}

bool greaterm(const Student& s1, const Student& s2)
{
  return s1.m > s2.m;
}

bool greatere(const Student& s1, const Student& s2)
{
  return s1.e > s2.e;
}

char course[] = {'A','C','M','E'};

int min_index(const vector<int>& arr)
{
  int idx = 0;
  for(int i=1;i<arr.size();++i)
  {
    if(arr[idx] > arr[i])
      idx = i;
  }
  return idx;
}

/*

int main()
{
  int n,m;
  cin >> n >> m;
  Student tmp;
  vector<Student> s;

  for(int i=0;i<n;++i)
  {
	  cin >> tmp.no >> tmp.c >> tmp.m >> tmp.e;
	  tmp.a = (tmp.c + tmp.m + tmp.e)/3;
	  s.push_back(tmp);
  }
  sort(s.begin(),s.end(),greatera);
  map<string,vector<int> > ranks;
  int score = 0;
  for(int i=0;i<s.size();++i)
  {
	  score = s[i].a;
	  int k = i-1;
	  while(k>-1 && s[k].a==score) k--;
	  ranks[s[i].no].push_back(k+2);
  }
  sort(s.begin(),s.end(),greaterc);
  for(int i=0;i<s.size();++i)
  {
	  score = s[i].c;
	  int k = i-1;
	  while(k>-1 && s[k].c==score) k--;
	  ranks[s[i].no].push_back(k+2);
  }
  sort(s.begin(),s.end(),greaterm);
  for(int i=0;i<s.size();++i)
  {
	  score = s[i].m;
	  int k = i-1;
	  while(k>-1 && s[k].m==score) k--;
	  ranks[s[i].no].push_back(k+2);
  }
  sort(s.begin(),s.end(),greatere);
  for(int i=0;i<s.size();++i)
  {
	  score = s[i].e;
	  int k = i-1;
	  while(k>-1 && s[k].e==score) k--;
	  ranks[s[i].no].push_back(k+2);
  }
  string no;
  for(int i=0;i<m;++i)
  {
    cin >> no;
    if(ranks.find(no) == ranks.end())
    {
      cout << "N/A" << endl;
    }
    else
    {
      vector<int> rank = ranks[no];
      int idx = min_index(rank);
      cout << rank[idx] << " " << course[idx] << endl;
    }
  }
  return 0;
}

*/