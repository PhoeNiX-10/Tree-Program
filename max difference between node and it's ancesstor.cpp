int util(Node* root,int& res)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    
    int val = min(util(root->left,res),util(root->right,res));
    
    res = max(res,root->data-val);
    
    return min(root->data,val);
}

int maxDiff(Node* root)
{
    int res = INT_MIN;
    int r= util(root,res);
    
    return res;
}

Algorithm-

1) if we reach the leaf node then return the value because leaf node cant be ancesstor of any node

2) and then at each internal node we recursively find the least node in left and right subtree of the that node.


