#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains no nodes with a value greater than the value of node x
Given the root of a binary tree root, return the number of good nodes within the tree. */ 

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

int DepthFristSearch(TreeNode* node, int maxVal) 
{
    if (!node)
    {
        return 0;
    }
    int res; 
    if(node->val >= maxVal) res = 1; 
    else res = 0; 
    maxVal = max(maxVal, node->val);
    res += DepthFristSearch(node->left, maxVal);
    res += DepthFristSearch(node->right, maxVal);
    return res;
}

int goodNodes(TreeNode* root) 
{
    return DepthFristSearch(root,root->val); 
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree:" << endl;
    printTree(root);
    /* 
    Original tree:
            9
        7
            6
    4
            3
        2
            1
    */

    cout << goodNodes(root) << endl; //Output : 3 
    return 0; 
}