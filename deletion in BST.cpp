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
	n->left=n->right=NULL;
	n->data=data;
	
	return n;
}
Node* ct(Node* root,int data)
{
	if(root==NULL)
	{
		 root=newNode(data);
	}
	else if(data<root->data)
		root->left = ct(root->left,data);
	else
		root->right = ct(root->right,data);
	
	return root;
}
void Inorder(Node* root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);	
	}
}
Node* findMin(Node* root)
{
	while(root->left!=NULL)
	{
		root = root->left;
	}
	return root;
}
Node* delete_node(Node* root,int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left = delete_node(root->left,data);
	else if(data>root->data)
		root->right = delete_node(root->right,data);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			//Node* temp = root;
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right,temp->data);
		}
	}
	return root;
}
int main()
{
	int n;
	cin>>n;
	int data;
	int*a=new int[n];
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = ct(root,data);
	}
	Inorder(root);
	int del;
	cout<<"Enter the Number to delete : ";
	cin>>del;
	delete_node(root,del);
	Inorder(root);
}
