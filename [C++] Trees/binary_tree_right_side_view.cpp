#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std; 

/* -------- Subject --------  
You are given the root of a binary tree. 
Return only the values of the nodes that are visible from the right side of the tree, ordered from top to bottom. */ 

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

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) 
    {
        TreeNode* rightSide = nullptr;
        int lenQ = q.size();
        for (int i = 0; i < lenQ; i++) 
        {
            TreeNode* node = q.front();
            q.pop();
            if (node) 
            {
                rightSide = node;
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (rightSide) 
        {
            res.push_back(rightSide->val);
        }
    }
    return res;
}

int main()
{
    TreeNode* root = new TreeNode(1); 
    root -> left = new TreeNode(2); 
    root -> right = new TreeNode(3); 
    for(const int & i : rightSideView(root))
    {
        cout << i << " "; 
    }
    //Output : 1 3 
    return 0; 
}