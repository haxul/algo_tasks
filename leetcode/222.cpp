
#include "./tree_node.cpp"

using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + this->countNodes(root->left) + this->countNodes(root->right);
    }
};