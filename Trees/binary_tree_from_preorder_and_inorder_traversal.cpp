#include <iostream> 
#include <vector> 
#include <algorithm> 

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

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) 
{
    if(preorder.empty() || inorder.empty()) return nullptr; 

    TreeNode* root = new TreeNode(preorder[0]); 
    auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); 
    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
    vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
    vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);
    return root;
}

int main()
{
    TreeNode* res = buildTree(vector<int>{1,2,3,4}, vector<int>{2,1,3,4}); 
    printTree(res); 
    /* Output : 
            4
        3
    1
        2 
    */
    return 0; 
}
