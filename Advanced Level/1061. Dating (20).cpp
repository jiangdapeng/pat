#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <string.h>

using namespace std;

const int MAX_SIZE = 65;

inline bool is_eng_letter(char c)
{
  return (c >='a' && c <='z') || (c >= 'A' && c <='Z');
}



int first2_common_letter(char* s1,int n1, char* s2, int n2, char& c1, char& c2)
{
  int i = 0;
  while(i < n1 && i < n2)
  {
    if(s1[i]>='A' && s1[i] <='G')
    {
      if(s1[i] == s2[i])
      {
        c1 = s1[i];
        i++;
        break;
      }
    }
    i++;
  }
  while(i < n1 && i < n2)
  {
    if((s1[i]>='0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N'))
    {
      if(s1[i] == s2[i])
      {
        c2 = s1[i];
        break;
      }
    }
    i++;
  }
  return 0;
}

int minutes(char* s1, int n1, char* s2, int n2)
{
  int i = 0;
  int j = 0;
  while(i < n1 && j < n2)
  {
    if(is_eng_letter(s1[i]))
      if(s1[i] == s2[j])
        return i;
    i++;
    j++;
  }
  return -1;
}

int main()
{
  map<char,string> c2str;
  c2str['A'] = "MON";
  c2str['B'] = "TUE";
  c2str['C'] = "WED";
  c2str['D'] = "THU";
  c2str['E'] = "FRI";
  c2str['F'] = "SAT";
  c2str['G'] = "SUN";
  char s1[MAX_SIZE];
  char s2[MAX_SIZE];
  char s3[MAX_SIZE];
  char s4[MAX_SIZE];
  scanf("%s",s1);
  scanf("%s",s2);
  scanf("%s",s3);
  scanf("%s",s4);

  char c1,c2;
  first2_common_letter(s1,strlen(s1),s2,strlen(s2),c1,c2);
  int m = minutes(s3,strlen(s3),s4,strlen(s4));
  int h = 0;
  if(c2 >= '0' && c2 <= '9')
    h = c2 - '0';
  else
    h = c2 - 'A' + 10;
  printf("%s %02d:%02d\n",c2str[c1].c_str(),h,m);
  return 0;
}
