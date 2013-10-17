#include <cstdio>

const int MAX_N = 100001;
int a[MAX_N];
bool visited[MAX_N];


int get_circle_size(int p)
{
  int c = 0;
  while(!visited[p])
  {
    visited[p] = true;
    ++c;
    p = a[p];
  }
  return c;
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0;i<n; ++i)
  {
    scanf("%d", a+i);
    visited[i] = false;
  }
  int count = 0;
  int c = 0;
  if(a[0]!=0)
    count = -2;
  for(int i=0; i<n; ++i)
  {
    c = get_circle_size(i);
    if(c > 1)
      count += c + 1; // the extra 1 is swap 0 to first position
  }
  printf("%d\n",count);
  return 0;
}
