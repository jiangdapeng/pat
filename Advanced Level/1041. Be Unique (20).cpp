#include <stdio.h>

const int MAX_BET_NUMBER = 10000;
const int MAX_NUMBER = 100000;

int main()
{
  char bucket[MAX_BET_NUMBER+1];
  int arr[MAX_NUMBER];
  for(int i=0;i<MAX_BET_NUMBER; ++i)
  {
    bucket[i] = 0;
  }
  int n;
  scanf("%d", &n);
  int tmp;
  int i = 0;
  for(i=0; i<n; ++i)
  {
    scanf("%d", &tmp);
    arr[i] = tmp;
    if(bucket[tmp]<2)
      bucket[tmp]++;
  }
  for(i=0;i<n;++i)
  {
    if(bucket[arr[i]] == 1)
      break;
  }
  if(i < n)
  {
    printf("%d\n",arr[i]);
  }
  else
  {
    printf("None\n");
  }
  return 0;
}

