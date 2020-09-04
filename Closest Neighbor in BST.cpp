 The task is to find the node with minimum absolute difference with given target value K.

void find(Node* root,int& maxi,int N)
{
	if(root==NULL)
		return;
		
	if(N<root->data);
		find(root->left,maxi,N);
		
	if(N>=root->data)
		maxi = max(root->data,maxi);
		
	find(root->right,maxi,N);
	
	return;
}
int closest_Neighbour_in_BST(Node* root,int N)
{
	int maxi=-1;
	find(root,maxi,N);
}
ALGORITHM-

1) If target value K is present in given BST, then it’s the node having minimum absolute difference.

2) If target value K is less than the value of current node then move to the left child.

3) If target value K is greater than the value of current node then move to the right child.
