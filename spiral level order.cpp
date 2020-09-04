/*   Method 1  with complexity O(n^2)
*/

int height(Node* root)
{
	if(root==NULL)
		return 0;
	int h = height(root->left);
	int r = height(root->right);
	
	return (max(h,r)+1);
}
void printSpiralUtil(Node* root,int level,bool itr)
{
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		if(itr)
		{
			printSpiralUtil(root->left,level-1,itr);
			printSpiralUtil(root->right,level-1,itr);
		}
		else
		{
			printSpiralUtil(root->right,level-1,itr);
			printSpiralUtil(root->left,level-1,itr);
		}
	}
}
void printSpiral(Node* root)
{
	int h = height(root);
	bool itr = false;
	
	for(int i=1; i<=h; i++)
	{
		printSpiralUtil(root,i-1,itr);
		
		itr = !itr;
	}
}

/* Method -2 using Two stacks with complexity O(n)
*/
void spiralPrint(Node* root)
{
	stack<Node*> s1;
	stack<Node*> s2;
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			Node* cur = s1.top();
			s1.pop();
			
			cout<<cur->data<<" ";
			
			if(cur->right)
				s2.push(cur->right);
			if(cur->left)
				s2.push(cur->left);
			
		}
		while(!s2.empty())
		{
			Node* cur = s2.top();
			s2.pop();
			
			cout<<cur->data<<" ";
			
			if(cur->left)
				s1.push(cur->left);
			if(cur->right)
				s1.push(cur->right);
		}
	}
}
