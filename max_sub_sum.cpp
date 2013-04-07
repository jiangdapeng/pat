/**
 * 1007 max subsequence sum
 * note: 
 * input 
 * 5
 * -1 -2 -3 -4 -5
 * output
 * 0 -1 -5
 * input 
 * 5
 * -1 0 -3 -4 -5
 * output
 * 0 0 0
 */
#include <iostream>
#include <vector>
using namespace std;

struct Result
{
  int sum;
  int start;
  int end;
};

Result max_sub_sum(const vector<int>& arr)
{
  int sum = 0;
  int max_sum = -1;
  int start = 0;
  int end = arr.size()-1;;
  Result result;
  result.start = 0;
  result.end = arr.size()-1;
  bool zero = false;
  for(int i=0;i < arr.size();++i)
  {
    sum += arr[i];
    if(!zero && arr[i]==0)
    {
      zero = true;// the first zero
    }
    // key step 1: sum = max(sum,0)
    if(sum < 0)
    {
      sum = 0;
      start = i+1;// maybe the new start point
    }
    else
    {
      end = i;// maybe the new end point
    }
    // key step 2: max_sum = max(max_sum,sum)
    if(max_sum < sum)
    {
      // update max_sum
      // only when zero appeared or sum > 0
      if(zero || sum >0)
      {
        max_sum = sum;
        result.start = start;
        result.end = end;
      }
    }
  }
  if(max_sum == -1)
    result.sum = 0;
  else
    result.sum = max_sum;
  return result;
}

int main()
{
  int n,elem;
  vector<int> arr;
  cin >> n;
  for(int i=0;i<n;++i)
  {
    cin >> elem;
    arr.push_back(elem);
  }
  Result result = max_sub_sum(arr);
  cout << result.sum << " " << arr[result.start] << " " << arr[result.end] << endl;
  return 0;
}

