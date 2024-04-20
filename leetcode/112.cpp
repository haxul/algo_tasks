#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./tree_node.cpp"


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode* node, int t, int cur) {
        if (node == nullptr) return false;
        if (node->left == nullptr && node->right == nullptr) {
            cur += node->val;
            if (cur == t) {
                return true;
            } else {
                return false;
            }
        }

        cur += node->val;

        return dfs(node->left, t, cur) || dfs(node->right, t, cur);
    }

};