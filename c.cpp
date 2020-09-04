#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
}*root = NULL;

Node* newNode(int data)
{
	Node* n=new Node();
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

Node* ct(Node* root,int data)
{
	if(root==NULL)
		root = newNode(data);
	else if(data<root->data)
		root->left = ct(root->left,data);
	else
		root->right = ct(root->right,data);
	
	return root;
}

void preorder(Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void put_in_arr(Node* root,vector<int>&v)
{
	if(root!=NULL)
	{
		put_in_arr(root->left,v);
		v.push_back(root->data);
		put_in_arr(root->right,v);
	}
}
void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
Node* arr_to_bst(vector<int> v,int s,int e)
{
	if(s>e)
		return NULL;
	int ind = s+(e-s)/2;
	Node* n=newNode(v[ind]);
	n->left = arr_to_bst(v,s,ind-1);
	n->right = arr_to_bst(v,ind+1,e);
	
	return n;
}
int main()
{
	int n,data;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root= ct(root,data);
	}
	preorder(root);
	
	vector<int> v;
	put_in_arr(root,v);
	root = arr_to_bst(v,0,v.size()-1);
	cout<<"\nBalanced tree is : \n";
	preorder(root);
	
}
