#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;
int sequence[MAX_SIZE];
bool first = true;

struct TreeNode 
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v=0)
	{
		value = v;
		left = right = NULL;
	}
	~TreeNode()
	{
		if (left)
		{
			delete left;
			left = NULL;
		}
		if (right)
		{
			delete right;
			right = NULL;
		}
	}
};

TreeNode* build_bst(int seq[],int n)
{
	if(n<1) return NULL;
	TreeNode* root = new TreeNode(seq[0]);
	int i=1;
	while(i < n && seq[i] < root->value) i++;
	root->left = build_bst(seq+1,i-1);
	root->right = build_bst(seq+i,n-i);
	return root;
}

TreeNode* build_bst_img(int seq[],int n)
{
	if(n < 1) return NULL;
	TreeNode* root = new TreeNode(seq[0]);
	int i=1;
	while(i< n && seq[i]>= root->value) i++;
	root->left = build_bst_img(seq+1,i-1);
	root->right = build_bst_img(seq+i,n-i);
	return root;
}

bool is_bst(int seq[],int n)
{
	if(n < 2)
		return true;
	int root = seq[0];
	int i=1;
	// find number greater or equal to root
	while(i<n && seq[i] < root) i++;
	for(int j=i;j<n;++j)
	{
		if(seq[j] < root) return false;
	}
	bool bLeft = is_bst(seq+1,i-1);
	bool bRight = is_bst(seq+i,n-i);
	return bLeft && bRight;
}
bool is_bst_img(int seq[],int n)
{
	if(n < 2) return true;
	int root = seq[0];
	int i=1;
	// find number less than root
	while(i < n && seq[i] >= root) i++;
	for (int j=i;j<n;++j)
	{
		if (seq[j] >= root)
		{
			return false;
		}
	}
	bool bLeft = is_bst_img(seq+1,i-1);
	bool bRight = is_bst_img(seq+i,n-i);
	return bLeft && bRight;
}

void postorder(TreeNode* tree)
{
	if(tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		if (first)
		{
			first = false;
			cout << tree->value;
		}
		else
		{
			cout << " " << tree->value;
		}
		
	}
}


int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;++i)
	{
		cin >> sequence[i];
	}
	TreeNode* bst = NULL;
	if (is_bst(sequence,n))
	{
		cout << "YES" << endl;
		bst = build_bst(sequence,n);
		postorder(bst);
	}
	else if (is_bst_img(sequence,n))
	{
		cout << "YES" << endl;
		bst = build_bst_img(sequence,n);
		postorder(bst);
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
	delete bst;
	return 0;
}