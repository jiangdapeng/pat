#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

struct Node
{
  int next;
  char c;
  bool visited;
};

int main()
{
  int s1, s2;
  int n;
  cin >> s1 >> s2 >> n;
  map<int,Node> data;
  int now,next;
  char c;
  Node tmp;
  for(int i=0;i<n;++i)
  {
    //cin >> now >> c >> next;
    scanf("%d %c %d",&now,&c,&next);
    tmp.next = next;
    tmp.c = c;
    tmp.visited = false;
    data[now] = tmp;
  }
  next = s1;
  while(next != -1)
  {
    data[next].visited = true;
    next = data[next].next;
  }

  int common = -1;
  next = s2;
  while(next !=-1)
  {
    if(data[next].visited == true)
    {
      // found 
      common = next;
      break;
    }
    next = data[next].next;
  }
  if(common == -1)
    printf("-1\n");
  else
    printf("%05d\n",common);
  return 0;
}

