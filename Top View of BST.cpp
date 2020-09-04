void TopView(Node* root)
{
	map<int,int> m;
	queue<pair<Node*,int>> q;
	
	q.push(make_pair(root,0));
	
	while(!q.empty())
	{
		pair<Node* root,int> cur = q.front();
		q.pop();
		
		if(m.find(cur.first->data)==m.end())
		{
			cout<<cur.first->data<<" ";
			m[cur.second] = cur.first->data;
		}
		if(cur.first->left!=NULL)
			q.push(make_pair(cur.first->left,cur.second-1));
		if(cur.second->right!=NULL)
			q.push(make_pair(cur.first->right,cur.second+1));
	}
}
