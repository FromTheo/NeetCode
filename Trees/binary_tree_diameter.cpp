#include <iostream> 

using namespace std; 

/* -------- Subject --------  
The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. 
The path does not necessarily have to pass through the root.
The length of a path between two nodes in a binary tree is the number of edges between the nodes.
Given the root of a binary tree root, return the diameter of the tree. */ 

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
    int left = DepthFirstSearch(root->left, res); 
    int right = DepthFirstSearch(root->right, res); 
    res = max(res, left + right); 
    return 1 + max(left, right);
}
    
int diameterOfBinaryTree(TreeNode* root) 
{
    int res = 0; 
    DepthFirstSearch(root, res); 
    return res; 
}

int main()
{   
    TreeNode* root = new TreeNode(1); 
    root -> right = new TreeNode(2); 
    root -> right -> left = new TreeNode(3); 
    root -> right -> left -> left = new TreeNode(5); 
    root -> right -> right = new TreeNode(4); 

    cout << "Diameter = " << diameterOfBinaryTree(root) << endl; //Output : Diameter = 3 

    return 0; 
}