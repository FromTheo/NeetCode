#include <iostream> 
#include <vector>
#include <deque> 

using namespace std; 

/* -------- Subject --------  
Given a binary tree root, return the level order traversal of it as a nested list, 
where each sublist contains the values of nodes at a particular level in the tree, from left to right. */ 

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

vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> rep; 
    deque<TreeNode*> q; //for push_front() 
    if(root != nullptr) q.push_back(root); 
    while(!q.empty())
    {
        vector<int> val; 
        for(int i = 0, len = q.size(); i < len; i++)
        {
            TreeNode* node = q.front(); 
            q.pop_front(); 
            val.push_back(node->val); 
            if(node->left != nullptr)
            {
                q.push_back(node->left); 
            }
            if(node->right != nullptr)
            {
                q.push_back(node->right);
            }
        }
        rep.push_back(val); 
    }
    return rep; 
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printTree(root); 
    cout << endl; 
    /* 
            7
        3
            6
    1
            5
        2
            4
    */ 
    for(const vector<int> & v : levelOrder(root))
    {
        for(const int&  i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output :
    1 
    2 3 
    4 5 6 7 */
    return 0; 
}
