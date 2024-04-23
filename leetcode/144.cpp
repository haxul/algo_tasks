#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./tree_node.cpp"


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        dfs(root, v);

        return v;
    }

    void dfs(TreeNode* n, vector<int>& v) {
        if (n == nullptr) return;

        v.push_back(n->val);

        dfs(n->left, v);
        dfs(n->right, v);
    }
};

