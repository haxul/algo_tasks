
#include "./tree_node.cpp"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);

        return root;
    }


    void dfs(TreeNode* n) {
        if (n == nullptr) return ;

        TreeNode* t;
        t = n->left;
        n->left = n->right;
        n->right = t; 

        dfs(n->left);
        dfs(n->right);
    }
};