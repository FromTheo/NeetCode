#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given the root of a binary tree, return its depth.
The depth of a binary tree is defined as the number of nodes along the longest path from the root node down to the farthest leaf node. */ 

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

int maxDepth(TreeNode* root) 
{
    if(root == nullptr) return 0; 
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(1);

    cout << "Original tree:" << endl;
    printTree(root);
    /* 
    Original tree:
                1
            9
        7
            6
    4
        2
    */ 
   cout << "Depth max. = " << maxDepth(root) << endl; // Output : Depth max. = 4  
   return 0; 
}