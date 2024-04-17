#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "./tree_node.cpp"

using namespace std;


class Solution {
public:
    int maxDepth(TreeNode* root) {
       if (root == nullptr) return 0;

       int l = maxDepth(root->left);        
       int r = maxDepth(root->right);

       return max(l, r) + 1;
    }
};

