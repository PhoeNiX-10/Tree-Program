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
	n->data = data;
	n->right = n->left = NULL;
	
	return n;
}
Node* bst(int a[],int s,int e)
{
	if(s>e)
		return NULL;
		
	int ind = (s + (e-s)/2);
	Node* n = newNode(a[ind]);
	n->left = bst(a,s,ind-1);
	n->right = bst(a,ind+1,e);
	return n;
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
int main()
{
	int n;
	cout<<"Enter size : ";
	cin>>n;
	
	int* a=new int[n];
	for(int i=0; i<n; i++)
	cin>>a[i];
	
	root = bst(a,0,n-1);
	
	preorder(root);
}
