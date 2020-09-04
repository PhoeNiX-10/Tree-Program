void printLeftBoundary(Node* root)
{
    if(root==NULL)
        return;
    if(root->left)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}
void printRightBoundary(Node* root)
{
    if(root==NULL)
        return;
    if(root->right)
    {
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }
}
void printLeaves(Node* root)
{
    if(root==NULL)
        return;
    
    printLeaves(root->left);
    
    if(!root->left && !root->right)
        cout<<root->data<<" ";
    
    printLeaves(root->right);
}
void printBoundary(Node *root)
{
     if(root==NULL)
        return;
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    
    printLeaves(root->left);
    printLeaves(root->right);
    
    printRightBoundary(root->right);
}
