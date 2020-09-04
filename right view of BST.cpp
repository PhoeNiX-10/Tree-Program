#include<iostream>
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
void Right_view(node* root,int level,int* max_level)
{
	if(root==NULL)
		return ;
	if(level>*max_level)
	{
		cout<<root->data<<" ";
		*max_level = level;
	}
	Right_view(root->right,level+1,max_level);
	Right_view(root->left,level+1,max_level);
}
void UtilRightView(node* root)
{
	int max_level=0;
	Right_view(root,1,&max_level);
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
//	printT(root);
UtilRightView(root);
	
}
