#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, 
return the lowest common ancestor (LCA) of the two nodes.
The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. 
The ancestor is allowed to be a descendant of itself. */ 

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    while(true)
    {
        if(root->val < p->val && root->val < q->val)
        {
            root = root->right; 
        }
        else if (root->val > p->val && root->val > q->val)
        {
            root = root->left; 
        }
        else return root; 
    }
}

int main()
{
    TreeNode* root = new TreeNode(5); 
    root -> left = new TreeNode(3); 
    root -> left -> left = new TreeNode(1); 
    root -> left -> right = new TreeNode(4); 
    root -> left -> left -> left = new TreeNode(2); 
    root -> right = new TreeNode(8); 
    root -> right -> left = new TreeNode(7); 
    root -> right -> right = new TreeNode(9); 

    TreeNode* ancestor = lowestCommonAncestor(root, root -> left, root -> right);

    return 0; 
}