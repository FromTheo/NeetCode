#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given the roots of two binary trees p and q, return true if the trees are equivalent, otherwise return false.
Two binary trees are considered equivalent if they share the exact same structure and the nodes have the same values. */ 

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

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p == nullptr && q == nullptr) return true; 
    if(p != nullptr && q != nullptr && p->val == q->val)
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false; 
}

int main()
{
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);

    TreeNode* root2 = new TreeNode(5); 
    root2->right = new TreeNode(7); 

    printTree(root1); 
    /* 
        7
    4
        2
    */
    printTree(root2); 
    /* 
        7
    5
    */    
    cout << isSameTree(root1, root2) << endl;  //Output : 0
    cout << isSameTree(root1, root1) << endl;  //Output : 1 

    return 0; 
}
