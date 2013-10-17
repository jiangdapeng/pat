/**
 * 1020. Tree Traversals (25)
 * construct binary tree(attention! : not binary search tree!) from postorder sequence
 * and inorder sequence
 */
#include <iostream>
#include <queue>

using namespace std;

const int MAX_NODES = 30;

struct Node
{
  int value;
  struct Node* left;
  struct Node* right;
};

// using postorder and inorder sequence to 
// reconstruct binary tree
Node* build(int postorder[],int inorder[], int n)
{
  if(n <=0)
    return NULL;
  Node* root = new Node;
  root->value = postorder[n-1];

  // find root value in inorder sequence
  int idx = 0;
  while(idx < n && inorder[idx] != root->value) ++idx;

  root->left = build(postorder, inorder, idx);
  root->right = build(postorder+idx, inorder + idx + 1, n-1-idx);
  
  return root;
}

void level_visit(Node* tree)
{
  if(tree == NULL)
  {
    return;
  }
  cout << tree->value;
  queue<Node*> tovisit;
  tovisit.push(tree->left);
  tovisit.push(tree->right);
  while(!tovisit.empty())
  {
    Node* t = tovisit.front();
    tovisit.pop();
    if(NULL != t)
    {
      cout << " " << t->value;
      tovisit.push(t->left);
      tovisit.push(t->right);
    }
  }
  cout << endl;
}

int main()
{
  int n;
  int postorder[MAX_NODES];
  int inorder[MAX_NODES];
  cin >> n;
  for(int i=0;i<n;++i)
  {
    cin >> postorder[i];
  }

  for(int i=0;i<n;++i)
  {
    cin >> inorder[i]; 
  }
  Node* tree = build(postorder,inorder, n);
  level_visit(tree);
  return 0;
}
