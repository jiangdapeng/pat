#include <iostream>
#include <queue>
#include <algorithm>

#include <stdio.h>
#include <math.h>

using namespace std;


class TNode
{
  public:
  TNode(int v)
  {
    value = v;
    left = NULL;
    right = NULL;
  }
  ~TNode()
  {
    if(left != NULL)
    {
      delete left;
      left = NULL;
    }
    if(right != NULL)
    {
      delete right;
      right = NULL;
    }
  }

  int value;
  TNode* left;
  TNode* right;
};

double log2(double x)
{
  return log(x)/ log(2);
}

int get_root_index(int n)
{
  if( n == 1 ) return 0;
  int full_level = (int)log2(n+1);
  int rest = n - ((1 << full_level) - 1);
  int left_rest = rest;
  if(rest > (1 << (full_level - 1)))
    left_rest =  1 << (full_level -1);
  return (n-rest-1)/2 + left_rest;
}

TNode* build_cbst(int data[],int n)
{
  // assume data is sorted asc
  if(n == 0) return NULL;
  int root_index = get_root_index(n);
  int root_v = data[root_index];
  TNode* root = new TNode(root_v);
  root->left = build_cbst(data,root_index);
  root->right = build_cbst(data+root_index+1,n - root_index -1);
  return root;
}

void level_visit_bst(TNode* bst)
{
  if(bst == NULL) return;
  queue<TNode*> q;
  q.push(bst);
  TNode* cur = NULL;
  bool first = true;
  while(!q.empty())
  {
    cur = q.front();
    if(first)
    {
      printf("%d",cur->value);
      first = false;
    }
    else
      printf(" %d",cur->value);
    q.pop();
    if(cur->left != NULL) q.push(cur->left);
    if(cur->right != NULL) q.push(cur->right);
  }
  printf("\n");
}
int main()
{
  int n;
  int data[1001];
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  {
    scanf("%d",&data[i]);
  }
  sort(data,data+n);
  TNode* bst = build_cbst(data,n);
  level_visit_bst(bst);
  delete bst;
  return 0;
}
