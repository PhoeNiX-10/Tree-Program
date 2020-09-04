#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* height;
}* root=NULL;
Node* newNode(int data)
{
	Node* n=new Node();
	n->data = data;
	n->left = n->right = NULL;
	n->height = 1;
	
	return n;
}
int Height(Node* n)
{
	if(n==NULL)
		return 0;
	else 
		return n->height;
}
int get_balance(Node* n)
{
	if(n==NULL)
		return 0;
	return (Height(n->height)-Height(n->height));
}
Node* Right_Right(Node* y)
{
	Node* x = y->left;
	Node* t2 = x->right;
	
	x->right = y;
	y->left = t2;
	
	y->height = max(Height(y->left),Height(y->right))+1;
	x->height = max(Height(x->left),Height(x->right))+1;
	
	return x;
}
Node* Left_Left(Node* x)
{
	Node* y = x->right;
	Node* t1 = y->left;
	
	y->left = x;
	x->right = t1;
	
	x->height = max(Height(x->left),Height(x->right))+1;
	y->height = max(Height(y->left),Height(y->right))+1;
	
	return y;
}
Node* AVL_tree(Node* root,int data)
{
	if(root==NULL)
		root = newNode(data);
	
	if(data<root->data)
		root->left = AVL_tre(root->left,data);
	
	else if(data>root->data)
		root->right = AVL_tree(root->right,data);
	else
		return root;
	
	int balance = get_balance(root);
	
	if(balance>1 && data<root->left->data)
		return Right_Right(root);
	
	else if(balance<-1 && data>root->right->data)
		return Left_Left(root);
	
	if (balance>1 && data>root->left->data)  
    {  
        root->left = Left_Left(root->left);  
        return Right_Right(root);  
    }  
  
    // Right Left Case  
    if (balance<-1 && data<root->right->data)  
    {  
        root->right = rightRotate(root->right);  
        return Left_Left(root);  
    }  
	
	
}
int main()
{
	int n,data;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		root = AVL_tree(root,data);
	}
}
