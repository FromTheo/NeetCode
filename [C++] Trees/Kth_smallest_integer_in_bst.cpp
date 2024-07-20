#include <iostream>
#include <stack>  

using namespace std; 

/* -------- Subject --------  
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.
A binary search tree satisfies the following constraints:
- The left subtree of every node contains only nodes with keys less than the node's key.
- The right subtree of every node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees are also binary search trees.*/ 

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

int kthSmallest(TreeNode* root, int k) 
{
    stack<TreeNode*> stack;
    TreeNode* curr = root;

    while (!stack.empty() || curr != nullptr) 
    {
        while (curr != nullptr) 
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        k--;
        if (k == 0) 
        {
            return curr->val;
        }
            curr = curr->right;
    }

    return -1; 
}

int main()
{
    TreeNode* root = new TreeNode(4); 
    root -> left = new TreeNode(3); 
    root -> left -> left = new TreeNode(2); 
    root -> right = new TreeNode(5); 

    cout << kthSmallest(root, 4) << endl; //Output : 5 

    return 0; 
}