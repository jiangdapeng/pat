#include <iostream>

using namespace std;

void reverse(int arr[], int size)
{
  int tmp =0;
  for(int i=0;i<size/2;++i)
  {
    tmp = arr[i];
    arr[i] = arr[size-1-i];
    arr[size-1-i] = tmp;
  }
}

void right_rotate(int arr[], int size, int m)
{
  // first reverse the array
  // and then reverse the first m number and the rest size-m number
  m = m%size;
  reverse(arr,size);
  reverse(arr,m);
  reverse(arr+m,size-m);
}

int main()
{
  int n,m;
  int elems[100];
  cin >> n >> m;
  for(int i=0;i<n;++i)
  {
    cin >> elems[i];
  }
  right_rotate(elems,n,m);
  cout << elems[0];
  for(int i=1;i<n;++i)
  {
    cout << " " << elems[i];
  }
  cout << endl;
  return 0;
}
