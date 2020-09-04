
int height(Node* root)
{
	if(root==NULL)
		return 0;
	int left_h = height(root->left);
	int right_h = height(root->right);
	
	return max(left_h,right_h)+1;
}
int diameter(Node* root)
{
	if(root==NULL)
		return 0;
		
	int l_height = height(root->left);
	int r_height = height(root->right);
	
	int l_diameter = diameter(root->left);
	int r_diameter = diameter(root->right);
	
	int fd = max(l_height+r_height+1,max(l_diameter,r_diameter));
	
	return fd;
}
