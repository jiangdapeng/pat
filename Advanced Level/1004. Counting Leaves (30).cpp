#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int nodes;
  int non_leaf;
  cin >> nodes >> non_leaf;
  vector<vector<int> > tree(100);
  for(int i=0;i< non_leaf;++i)
  {
    int root;// subtree root
    int num;
    cin >> root >> num;
    vector<int> subtree;
    for(int j=0;j<num;++j)
    {
      int child;
      cin >> child;
      subtree.push_back(child);
    }
    tree[root] = subtree;
  }
  // count leaf node of each level
  queue<int> current;
  queue<int> next;
  current.push(1);// root
  vector<int> counter;
  int count=0;
  while(true)
  {
    count = 0;
    while(!current.empty())
    {
      int node = current.front();
      current.pop();
      int nchild = tree[node].size();
      if(nchild ==0)
      {
        count++;// one leaf
      }
      for(int i=0;i<nchild;++i)
      {
        next.push(tree[node][i]);
      }
    }
    counter.push_back(count);
    if(next.empty())
      break;
    swap(current,next);
  }
  for(int i=0;i<counter.size()-1;++i)
  {
    cout << counter[i] << " "; 
  }
  cout << counter[counter.size()-1] << endl;
  return 0;
}
