#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
}*root=NULL;
Node* newNode(int data)
{
	Node* n=new Node();
	n->data=data;
	n->left=n->right=NULL;
	
	return n;
}
Node* ct(Node* root,int data)
{
	if(root==NULL)
		root = newNode(data);
	else if(root->data>data)
		root->left = ct(root->left,data);
	else
		root->right = ct(root->right,data);
	
	return root;
}
void inorder(Node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right); 
	}
}
int sum_root_leaf(Node* root,int val)
{
	if(root==NULL)
		return 0;
	val = val*10+root->data;
	
	if(root->left==NULL && root->right==NULL)
		cout<<val<<" ";
	
	sum_root_leaf(root->left,val);
	sum_root_leaf(root->right,val);
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
	//inorder(root);
	sum_root_leaf(root,0);
}
