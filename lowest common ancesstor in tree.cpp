Node* lowestCommonAncesstor(Node* root, int n1,int n2)
{
	if(root==NULL)
		return NULL;
	
	if(root->data==n1 || root->data==n2)
		return root;
	
	Node* left_lca = lowestCommonAncesstor(root->left,n1,n2);
	Node* right_lca = lowestCommonAncesstor(root->right,n1,n2);
	
	if(left_lca && right_lca)
		return root;
	
	return (left_lca!=NULL)? left_lca:right_lca;

}

Algorithm -

1) Search the two nodes in the binary tree

2) if node is found in the tree then return the node

3) else return NULL

4) when some node receives both left and right node then it will be its LCA

5) else return what it receives


