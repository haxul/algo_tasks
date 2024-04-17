
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;

        dfs(root,v);

        return v;
    }


    void dfs(TreeNode* n , vector<int> &v) {
        if (n == nullptr) return;

        dfs(n->left, v);
        v.push_back(n->val);
        dfs(n->right, v);
    }
};