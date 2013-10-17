/*
 * 总是有两个case wa，不知道哪里有问题，求教- -
 */
#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 2000002;
long int ab[MAX_N];
long int a[MAX_N/2];
long int b[MAX_N/2];

int main()
{
  int n1,n2;
  scanf("%d",&n1);
  for(int i=0;i<n1;++i)
  {
    scanf("%d", &a[i]);
  }
  scanf("%d",&n2);
  for(int i=0;i<n2;++i)
  {
    scanf("%d",&b[i]);
  }
  int i = 0;
  int j = 0;
  int k = 0;
  while(i < n1 && j < n2)
  {
    if(a[i] < b[j])
    {
      ab[k++] = a[i++];
    }
    else
    {
      ab[k++] = b[j++];
    }
  }
  if(i==n1)
  {
    for(; j< n2;++j)
    {
      ab[k++] = b[j];
    }
  }
  else if(j == n2)
  {
    for(; i < n1;++i)
      ab[k++] = a[i];
  }
  int media = (k-1)/2;
  printf("%ld\n",ab[media]);
  return 0;
}
