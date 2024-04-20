#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./tree_node.cpp"

#define null -1

class Solution {
   public:
    bool result = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);

        return result;
    }

    int dfs(TreeNode* n) {
        if (result == false) {
            return 0;
        }
        if (n == nullptr) {
            return 0;
        }

        int l = dfs(n->left);
        int r = dfs(n->right);

        if (abs(l - r) > 1) {
            result = false;
            return 0;
        }

        return max(l, r) + 1;
    }
};

int main() {
    Solution s;
    vector<int> v = {3, 9, 20, null, null, 15, 7};
    auto tree = buildBinaryTree(v);
    std::cout << s.isBalanced(tree) << "\n";

    return 0;
}