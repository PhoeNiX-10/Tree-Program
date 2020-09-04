bool isMirror(Node* root_1,Node* root_2)
{
	if(root_1==NULL && root_2==NULL)
		return false;
	
	if(root_1==NULL || root_2==NULL)
		return false;
	
	return (root_1->data==root_2->data && isMirror(root_1->left,root_2->right)&&isMirror(root_1->right,root_2->left));
}
