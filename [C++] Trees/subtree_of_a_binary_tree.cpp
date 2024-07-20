#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given the roots of two binary trees root and subRoot, 
return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself. */ 

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

bool isSameTree(TreeNode* root, TreeNode* subRoot)
{
    if(root == nullptr && subRoot == nullptr) return true; 
    if(root != nullptr && subRoot != nullptr && root->val == subRoot->val)
    {
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
    return false; 
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
    if(subRoot == nullptr) return true; 
    if(root == nullptr) return false; 
    if(isSameTree(root, subRoot)) return true; 
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
}

int main()
{
    TreeNode* root = new TreeNode(1); 
    root -> left = new TreeNode(2); 
    root -> right = new TreeNode(3); 
    root -> left -> left = new TreeNode(4); 
    root -> left -> right = new TreeNode(5); 

    TreeNode * subRoot = new TreeNode(2); 
    subRoot -> left = new TreeNode(4); 
    subRoot -> right = new TreeNode(5); 

    printTree(root); 
    /* 
        3
    1
            5
        2
            4
    */
    cout << endl; 
    printTree(subRoot);
    /* 
        5
    2
        4
    */ 
    cout << isSubtree(root, subRoot) << endl; //Output : 1  
    
    return 0; 
}