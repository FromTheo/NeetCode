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

bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode)
{
    if (!node) return true;
    
    if (minNode && node->val <= minNode->val) return false;
    if (maxNode && node->val >= maxNode->val) return false;
        
    return isValidBSTHelper(node->left, minNode, node) && isValidBSTHelper(node->right, node, maxNode);
}

bool isValidBST(TreeNode* root)
{
    return isValidBSTHelper(root, nullptr, nullptr);
}

int main()
{
    TreeNode* root1 = new TreeNode(2); 
    root1 -> left = new TreeNode(1); 
    root1 -> right = new TreeNode(3); 

    TreeNode* root2 = new TreeNode(1); 
    root2 -> left = new TreeNode(2); 
    root2 -> right = new TreeNode(3); 

    printTree(root1);
    /* Output : 
        3
    2
        1
    */ 
    cout<< "\n"; 
    printTree(root2); 
    /* Output : 
        3
    1
        2
    */
    cout << isValidBST(root1) << endl; //Output : 1 
    cout << isValidBST(root2) << endl; //Output : 0
    
    return 0; 
}