int util(Node* root,int& res)
{
    if(root==NULL)
        return 0;
        
    if(root->left==NULL && root->right==NULL)
        return root->data;
        
    int ls = util(root->left,res);
    int rs = util(root->right,res);
    
    if(root->left!=NULL && root->right!=NULL)
    {
        res = max(res,ls+rs+root->data);
        
        return max(ls,rs)+root->data;
    }
    return (!root->left)?rs+root->data:ls+root->data;
}
int maxPathSum(struct Node *root)
{
    int res=INT_MIN;
    util(root,res);
    return res;
}

Algorithm- 

For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X.
 We add the two values with X->data, and compare the sum with maximum path sum found so far
