#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given a binary tree, return true if it is height-balanced and false otherwise.
A height-balanced binary tree is defined as a binary tree in which the left and right subtrees 
of every node differ in height by no more than 1. */ 

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
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

bool isBalanced(TreeNode* root) 
{
    if(root == nullptr) return true;
    if(abs(maxDepth(root->left)-maxDepth(root->right))>1) return false;
    if(isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4); 

    TreeNode* root2 = new TreeNode(1); 
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4); 
    root2->right->right->right = new TreeNode(5); 

    printTree(root); 
    /* Output : 
            4
        3
    1
        2 */
    cout << endl; 
    printTree(root2); 
    /* Output : 
                5
            4
        3
    1
        2 */
    cout << isBalanced(root) << endl;  // Output : 1 
    cout << isBalanced(root2) << endl; // Output : 0 
    
    return 0; 
}