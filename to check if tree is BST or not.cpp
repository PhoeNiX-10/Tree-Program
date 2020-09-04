#include<bits/stdc++.h>
using namespace std;

struct node
{
	node* left;
	node* right;
	int data;
}*root=NULL;

node* newNode(int data)
{
	node* n=new node();
	n->data=data;
	n->left = NULL;
	n->right= NULL;
	
	return n;
}
node* ct(node* root,int data)
{
	if(root==NULL)
	{
		root = newNode(data);
	}
	else if(root->data>data)
		root->left = ct(root->left,data);
	else
		root->right = ct(root->right,data);
}
void printT(node* root)
{
	if(root!=NULL)
	{
		printT(root->left);
		cout<<root->data<<" ";
		printT(root->right);
	}
}
bool isBST(node* root)
{
	static node* prev = NULL;
	
	if(root)
	{
		if(!isBST(root->left))
			return false;
		
		if(prev!=NULL && prev->data>=root->data)
			return false;
		
		prev = root;
		
		return (isBST(root->right));
	}
	return true;
}
int height_T(node* root)
{
	if(root==NULL)
		return 0;
	int l_t = height_T(root->left);
	int r_t = height_T(root->right);
	
	return (max(l_t,r_t)+1);
}
int main()
{
	int n,data;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = ct(root,data);
	}
	printT(root);
	cout<<"\n"<<height_T(root);
	cout<<"\n";
	cout<<isBST(root);
}
