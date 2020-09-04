struct TreeNode
{
    vector<TreeNode*> children;
    char value;
};

class TreeDictionary
{
    TreeNode *root;
public:
    TreeDictionary()
    {
        root = new TreeNode();
        root->value = 0;
    }

    TreeNode *CreateNode(char data)
    {
        TreeNode *parent_node = new TreeNode;
        if (parent_node)
            parent_node->value = data;
        return parent_node;
    }
    TreeNode* SearchElement(TreeNode *NextNode, char *data, int& val)
    {
        bool bVal = false;
        for (vector<TreeNode*>::iterator it = NextNode->children.begin(); it != NextNode->children.end(); it++)
        {
            if ((*it)->value == *(data))
                return SearchElement((*it), ++data, ++val);
        }
        return NextNode;

    }
    TreeNode *InsertNode(TreeNode *parent, TreeNode *ChildNode, char data)
    {
        if (parent == NULL)
            ChildNode = CreateNode(data);
        else
        {
            TreeNode *childNode = CreateNode(data);
            parent->children.push_back(childNode);
            return childNode;
        }
        return ChildNode;
    }

    void InsertMyString(string str)
    {
        TreeNode *NextNode = root;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '\0')
                return;
            cout << str[i] << endl;
            if (NextNode->value == 0)
            {
                NextNode->value = str[i];
                continue;
            }
            else if (NextNode->value != str[i])
            {
                NextNode = InsertNode(NextNode, NULL, str[i]);
            }
            else
            {
                TreeNode *node;
                node = SearchElement(NextNode, &str[++i], i);
                NextNode = InsertNode(node, NULL, str[i]);
            }
        }
    }
};

int main()
{
    TreeDictionary td;
    td.InsertMyString("Monster");
    td.InsertMyString("Maid");
    td.InsertMyString("Monday");
    td.InsertMyString("Malli");
    td.InsertMyString("Moid");
    return 0;
}
