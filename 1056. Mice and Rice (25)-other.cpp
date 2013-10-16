#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>

int weight[1000];
int space1[1000];
int space2[1000];
int ranks[1000];
int rankmap[1000];
int* order;
int* result;

bool cmp(int index1,int index2)
{
  return weight[index1] > weight[index2];
}

int main()
{
  int num;
  int group;
  order = space1;
  result = space2;

  scanf("%d%d",&num,&group);

  for(int i = 0 ; i < num; i++)
  {
      scanf("%d",weight+i);
  }

  for(int i = 0 ; i < num; i++)
  {
      scanf("%d",order+i);
  }

  int round = 0;
  int left = num;
  int start = 0;
  int end = 0;
  int *tmp;

  while(left > 1)
  {
      int count = 0;
      start = 0;
      end = 0;
      while(end < left)
      {
          end = (start+group) <= left ?  (start+group) : (left);
          sort(order+start,order+end,cmp);
          result[count++] = *(order+start);
          printf("max order[%d]=%d\n",start,order[start]);
          for(int k = start; k < end ; k++)
          {
              int index = order[k];
              ranks[index] = round;
          }
          start = end;
      }

      //exchange
      tmp = order;
      order = result;
      result =  tmp;
      //
      rankmap[round] = count+1;  //how many before
      left = count;
      round++;
  }

  ranks[order[0]] = round;
  rankmap[round] = 1;

  for(int i = 0 ; i < num ; i++)
  {
    printf("%d ",ranks[i]);
  }
  printf("\n");

  for(int i = 0 ; i < num ; i++)
  {
      if(i!=0)
          printf(" ");
      printf("%d",rankmap[ranks[i]]);
  }
  printf("\n");
  return 0;
}
