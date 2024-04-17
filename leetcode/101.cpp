#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "./tree_node.cpp"

using namespace std;


typedef TreeNode t;

class Solution {
   public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(t *n1, t *n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr) return false;
        if (n2 == nullptr) return false;

        if (n1->val != n2->val) return false;

        return dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
    }
};

int main() {
    vector<int> v = {1, 2, -1, 3};
    TreeNode* root = buildBinaryTree(v);

    Solution s;

    cout << s.isSymmetric(root) << '\n';

    return 0;
}