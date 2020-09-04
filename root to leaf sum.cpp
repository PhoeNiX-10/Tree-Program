long long util(Node* root,int val)
{
	if(root==NULL)
		return 0;
	
	val = val*10 + root->data;
	
	if(root->left==NULL && root->right==NULL)
		return val;
	
	return util(root->left,val)+util(root->right,val);
}
long long root_to_leaf_sum(Node* root)
{
	long long ans = util(root,0);
	return ans;
}
