#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. 
A node can not appear in the sequence more than once. The path does not necessarily need to include the root.
The path sum of a path is the sum of the node's values in the path.*/ 

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

int DepthFirstSearch(TreeNode* root, int& res)
{
    if(!root) return 0; 
    int leftMax = max(DepthFirstSearch(root->left, res), 0);
    int rightMax = max(DepthFirstSearch(root->right, res), 0);
    res = max(res, root->val + leftMax + rightMax);
    return root->val + max(leftMax, rightMax); 
}

int maxPathSum(TreeNode* root) 
{
    int res = root->val; 
    DepthFirstSearch(root, res); 
    return res; 
}

int main()
{
    TreeNode* root = new TreeNode(-15); 
    root -> left = new TreeNode(10); 
    root -> right = new TreeNode(20); 
    root -> right -> left = new TreeNode(15); 
    root -> right -> left -> left = new TreeNode(-5); 
    root -> right -> right = new TreeNode(5); 

    cout << maxPathSum(root) << endl; //Output : 40 

    return 0; 
}