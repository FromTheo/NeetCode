#include <iostream> 
#include <string> 
#include <queue>

using namespace std; 

/* -------- Subject --------  
You are given the root of a binary tree root. Invert the binary tree and return its root. */ 

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode* root, int depth = 0)
{
    if (root == nullptr) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << root->val << endl;
    printTree(root->left, depth + 1);
}

string serialize(TreeNode* root) 
{
    if(!root) 
    {
        return "NULL,";
    }
    return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
}

TreeNode* deserialize_helper(queue<string> &q) 
{
    string s=q.front();
    q.pop();
    if(s=="NULL")return NULL;
    TreeNode* root=new TreeNode(stoi(s));
    root->left=deserialize_helper(q);
    root->right=deserialize_helper(q);
    return root;
}

TreeNode* deserialize(string data) 
{
    queue<string> q;
    string s;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]==',')
        {
            q.push(s);
            s="";
            continue;
        }
        s+=data[i];
    }
    if(s.size()!=0)q.push(s);
    return deserialize_helper(q);
}

int main()
{
    TreeNode* root = new TreeNode(1); 
    root -> left = new TreeNode(2); 
    root -> right = new TreeNode(3); 
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(5);  

    cout << serialize(root) << endl; // Output : 1,2,NULL,NULL,3,4,NULL,NULL,5,NULL,NULL 

    printTree(deserialize(serialize(root))); 
    /* Output : 
            5
        3
            4
    1
        2
    */ 
    return 0; 
}
