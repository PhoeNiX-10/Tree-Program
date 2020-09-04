int height(Node* root,bool& c)
{
    if(root==NULL)
        return 0;
    
    int hl = height(root->left,c);
    int rl = height(root->right,c);
    
    if(abs(hl-rl)>1)
        c = false;
    
    return max(hl,rl)+1;
}
bool isBalanced(Node *root)
{
    if(root==NULL)
        return true;
    bool c = true;
    height(root,c);
    
    return c;
}

