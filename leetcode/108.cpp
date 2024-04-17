#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./tree_node.cpp"

using namespace std;

typedef  vector<int> vi;
typedef TreeNode t;

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        return build(nums, 0, ssize(nums) - 1);
    }

   private:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l]);
        int m = (l + r) / 2;

        TreeNode* ln = build(nums, l, m - 1);
        TreeNode* rn = build(nums, m + 1, r);

        return new TreeNode(nums[m], ln , rn);
    }
};

int main() {
    vi v = {-10,-3,0,5,9};
    Solution s;
    TreeNode* root = s.sortedArrayToBST(v);
    return 0;    
}