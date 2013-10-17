#include <cstdio>

using namespace std;

struct Node
{
  int v;
  int h;
  Node * left;
  Node * right;
};

int max(int a, int b)
{
  return a > b?a:b;
}

int get_height(Node* root)
{
  if(root == NULL) return -1;
  else return root->h;
}

Node* leftleft(Node* pp, Node* p)
{
  pp->left = p->right;
  p->right = pp;
  pp->h = max(get_height(pp->left),get_height(pp->right)) + 1;
  p->h = max(get_height(p->left), get_height(p->right)) + 1;
  return p;
}

Node* rightright(Node* pp, Node* p)
{
  pp->right = p->left;
  p->left = pp;
  pp->h = max(get_height(pp->left),get_height(pp->right)) + 1;
  p->h = max(get_height(p->left), get_height(p->right)) + 1;
  return p;
}

Node* leftright(Node* pp, Node* p)
{
  Node* tmp = p->right;
  p->right = tmp->left;
  pp->left = tmp->right;
  tmp->right = pp;
  tmp->left = p;
  pp->h = max(get_height(pp->left),get_height(pp->right)) + 1;
  p->h = max(get_height(p->left), get_height(p->right)) + 1;
  tmp->h = max(get_height(tmp->left), get_height(tmp->right)) + 1;
  return tmp;
}

Node* rightleft(Node* pp, Node* p)
{
  Node* tmp = p->left;
  pp->right = tmp->left;
  p->left = tmp->right;
  tmp->left = pp;
  tmp->right = p;
  pp->h = max(get_height(pp->left),get_height(pp->right)) + 1;
  p->h = max(get_height(p->left), get_height(p->right)) + 1;
  tmp->h = max(get_height(tmp->left), get_height(tmp->right)) + 1;
  return tmp;
}

Node* insert(Node* root, int value)
{
  if(root == NULL)
  {
    // empty tree
    root = new Node;
    root->v = value;
    root->h = 0;
    root->left = root->right = NULL;
    return root;
  }
  Node* p = root;
  if(value > p->v)
  {
    p->right = insert(p->right, value);
  }
  else if(value < p->v)
  {
    p->left = insert(p->left, value);
  }
  else return p; // value already exists
  // to check if rotate is necessary
  int lpath = 0;
  int rpath = 0;
  lpath = get_height(p->left) + 1;
  rpath = get_height(p->right) + 1;
  p->h = max(lpath,rpath);
  Node * pp = p; // keep current root;
  if(lpath - rpath == 2)
  {
    p = p->left;
    if(get_height(p->left) > get_height(p->right))
      p = leftleft(pp,p);
    else
      p = leftright(pp,p);
  }
  else if(rpath - lpath == 2)
  {
    p = p->right;
    if(get_height(p->right) > get_height(p->left))
      p = rightright(pp,p);
    else
      p = rightleft(pp,p);
  }
  return p;
}

int main()
{
  int n;
  int a;
  Node* root = NULL;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  {
    scanf("%d",&a);
    root = insert(root,a);
  }
  printf("%d\n",root->v);
  return 0;
}
