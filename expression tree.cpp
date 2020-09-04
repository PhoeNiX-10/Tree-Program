bool check(string data)
{
    if(data=="+"||data=="-"||data=="*"||data=="/")
        return true;
    
    return false;
}
int calculate(int a, int b, string o)
{

    
    switch(o[0])
    {
        case '+' : return (a+b);
        case '-' : return (a-b);
        case '*' : return (a*b);
        case '/' : return (a/b);
    }
}

int evalTree(node* root)
{
    if(root!=NULL)
    {
        if(!check(root->data))
        {
            int r = atoi(root->data.c_str());
            return r;
        }
        int a = evalTree(root->left);
        int b = evalTree(root->right);
        
        return calculate(a,b,root->data);
    }
}

