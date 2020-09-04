#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
}*root=NULL;

node* newNode(int data)
{
	node* n=new node();
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	
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

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void count_leaf_nodes(node* root,int &count)
{
	if(root!=NULL)
	{
		count_leaf_nodes(root->left,count);
		count_leaf_nodes(root->right,count);
		if(root->left==NULL && root->right==NULL)
			count++;
	}
}
int main()
{
	int n;
	cin>>n;
	int data;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root=ct(root,data);
	}
//	inorder(root);
	int count=0;
	count_leaf_nodes(root,count);
	cout<<count;
}
