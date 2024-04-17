#include <queue>
#include <vector>


using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode* buildBinaryTree(vector<int>& nums) {
    int p = 0;
    TreeNode* root = new TreeNode(nums[0]);

    queue<TreeNode*> queue;
    queue.push(root);
    while (true) {
        TreeNode* cur = queue.front();
        queue.pop();

        if (cur->left == nullptr) {
            p++;
            if (p >= nums.size()) return root;
            if (nums[p] != -1) {
                auto node = new TreeNode(nums[p]);
                cur->left = node;
                queue.push(node);
            }
        }

        if (cur->right == nullptr) {
            p++;
            if (p >= nums.size()) return root;
            if (nums[p] != -1) {
                auto node = new TreeNode(nums[p]);
                cur->right = node;
                queue.push(node);
            }
        }

        if (queue.empty()) return root;
    }
}