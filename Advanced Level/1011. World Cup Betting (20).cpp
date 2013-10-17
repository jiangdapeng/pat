#include <iostream>
#include <stdio.h>

using namespace std;

int max_idx(float arr[],int size)
{
  int idx = 0;
  for(int i=1;i<size;++i)
  {
    if(arr[idx] < arr[i])
      idx = i;
  }
  return idx;
}

char bets[3] = {'W','T','L'};

int main()
{
  float game1[3];
  float game2[3];
  float game3[3];
  cin >> game1[0] >> game1[1] >> game1[2];
  cin >> game2[0] >> game2[1] >> game2[2];
  cin >> game3[0] >> game3[1] >> game3[2];
  int idx1 = max_idx(game1,3);
  int idx2 = max_idx(game2,3);
  int idx3 = max_idx(game3,3);
  float profit = (game1[idx1]*game2[idx2]*game3[idx3]* 0.65 - 1)*2; 
  printf("%c %c %c %.2f", bets[idx1], bets[idx2], bets[idx3],profit);
  return 0;
}
