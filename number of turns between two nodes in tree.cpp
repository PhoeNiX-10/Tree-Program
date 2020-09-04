Node* Lowest_Common_Ancesstor(Node* root,int a,int b)
{
	if(root==NULL)
		return NULL;
	
	if(root->data==a || root->data==b)
		return root;
	
	Node* lca_l = Lowest_Common_Ancesstor(root->left,a,b);
	Node* lca_r = Lowest_Common_Ancesstor(root->right,a,b);
	
	if(lca_l && lca_r)
		return root;
	
	return (lca_l!=NULL)?lca_l:lca_r;
}
bool countTurn(Node* root,int key,bool turn,int* count)
{
	if(root==NULL)
		return false;
	if(turn==true)
	{
		countTurn(root->left,key,turn,count);
			return true;
		countTurn(root->right,key,!turn,count);
			*count+=1;
			return truel
	}
	else
	{
		countTurn(root->right,key,turn,count);
			return true;
		countTurn(root->left,key,!turm,count);
			*count+=1;
			return true;
	}
	return false;
}
int NumberofTurns(Node* root,int a,int b)
{
	Node* LCA = Lowest_Common_Ancesstor(root,a,b);
	
	if(LCA==NULL)
		return -1;
	
	int count=0;
	if(LCA->data!=first && LCA->data!=second)
	{
		if(countTurn(root->right,second,false,&count)||countTurn(root->left,second,true,&count));
		
		if(countTurn(root->left,first,true,&count)||countTurn(root->right,first,false,&count));
		
		return count+1;
	}
	else if(LCA->data==first)
	{
		countTurn(root->right,second,false,&count);
		countTurn(root->left,second,true,&count);
		return count;
	}
	else
	{
		countTurn(root->left,first,true,&count);
		countTurn(root->right,first,false,&count);
		return count;
	}
}




