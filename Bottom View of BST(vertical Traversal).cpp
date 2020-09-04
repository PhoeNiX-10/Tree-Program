void fill(Node *root,int i,map<int,vector<int>>& m)
{
    if(root==NULL)
    	return;
    
    m[i].push_back(root->data);
    
	fill(root->left,i-1,m);
    
	fill(root->right,i+1,m);
    
}
void bottomView(Node *root)
{
   map<int,vector<int>>m;
   // Your Code Here
   fill(root,0,m);
   for(auto it=m.begin();it!=m.end();it++)
   {
       cout<<it->second[(it->second).size()-1]<<" ";
   }
   
  // m.clear();
   
}

