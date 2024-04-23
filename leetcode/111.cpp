
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./tree_node.cpp"

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return minDepth_(root);
    }

    int minDepth_(TreeNode* root) {
        if (root == nullptr) return __INT32_MAX__;
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int l = minDepth_(root->left);
        int r = minDepth_(root->right);

        return min(l, r) + 1;
    }
};
