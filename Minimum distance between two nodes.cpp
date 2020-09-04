/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/
   
class Graph
{
    private:
    vector <int> adjList[102];
    
    public:
        void addEdge(int a, int b)
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            
        }
         void fill(Node *root)
        {
            if(!root)
                return;
            fill(root->left);
            fill(root->right);
            
            if(root->left)
                addEdge(root->data, root->left->data);
            if(root->right)
                addEdge(root->data, root->right->data);
        }
        Graph(Node *root)
        {
            fill(root);
        }
       
        int bfs(int start, int end)
        {
            queue <pair<int,int>> q;
            bool visited[102];
            
            q.push(make_pair(start,0));
            visited[start] = true;
            
            while(!q.empty())
            {
                pair<int,int> current = q.front();
                if(current.first == end)
                    return current.second;
                q.pop();
                
                for(int i = 0; i < adjList[current.first].size(); i++)
                {
                    int actual = adjList[current.first][i]; 
                    if(!visited[actual])
                    {
                        visited[actual] = true;
                        q.push(make_pair(actual, current.second + 1));
                    }
                }
            }
            return 0;
        }
};
int findDist(Node* root, int a, int b)
{
    Graph g(root);
    return g.bfs(a,b);
    // Your code here 
}

Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
        return NULL;
    if(root->data==a || root->data==b)
        return root;
    
    Node* lcal = lca(root->left,a,b);
    Node* lcar = lca(root->right,a,b);
    
    if(lcal && lcar)
        return root;
    
    return (lcal!=NULL)?lcal:lcar;
}
int finD(Node* lcan,int a,int dep)
{
    if(lcan==NULL)
        return 0;
    if(lcan->data==a)
        return dep;
    int dis = finD(lcan->left,a,dep+1);
    if(dis!=0)
        return dis;
    dis = finD(lcan->right,a,dep+1);
}
int findDist(Node* root, int a, int b)
{
    Node* lca_n = lca(root,a,b);
    
   int  dis1 = finD(lca_n,a,0);
    int dis2 = finD(lca_n,b,0);
    
    return dis1+dis2; 
}
