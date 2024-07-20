#include <iostream> 

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

TreeNode* invertTree(TreeNode* root) 
{
    if(root == nullptr) return nullptr; 
    TreeNode* node = new TreeNode(root->val); 

    node->right = invertTree(root->left); 
    node -> left = invertTree(root->right); 
    return node;  
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

    TreeNode* invertedRoot = invertTree(root);

    cout << "\nInverted tree:" << endl;
    printTree(invertedRoot);
    /* 
    Inverted tree:
            1
        2
            3
    4
            6
        7
            9 */

    return 0; 
}
