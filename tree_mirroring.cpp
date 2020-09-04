#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
}*root=NULL;

node* newNode(int data)
{
	node* nn=new node();
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

node* create_t(node* r,int data)
{
	if(r==NULL)
	{
		r=newNode(data);
	}
	else if(data<r->data)
	{
		r->left=create_t(r->left,data);
	}
	else
	{
		r->right=create_t(r->right,data);
	}
	
	return r;
}
node* mirror(node* root)
{
	if(root==NULL)
	return NULL;
	
	node* nn=newNode(root->data);
	
	nn->right=mirror(root->left);
	nn->left=mirror(root->right);
	
	return nn;
}

void inorder(node* ptr)
{   
    // cout<<"in";
	if(ptr!=NULL)
	{
		
		inorder(ptr->left);
		cout<<ptr->data<<" ";
		inorder(ptr->right);
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
		root=create_t(root,data);
	}
	inorder(root);
	
	node* p=mirror(root);
	cout<<"\n";
	inorder(p);
}

void mirror(Node* node) 
{
     if(node==NULL)
        return;
    else if(node->left==NULL && node->right==NULL)
        return;
    
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    mirror(node->left);
    mirror(node->right);
    
}
