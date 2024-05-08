#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i = 0; i < ssize(nums); i++) {
            if (set.contains(nums[i])) {
                return true;
            }

            set.insert(nums[i]);
        }

        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k > ssize(nums) - 1) {
            return this->containsDuplicate(nums);
        }
        unordered_set<int> win;

        for (int i = 0; i <= k; i++) {
            win.insert(nums[i]);
        }

        if (win.size() != k + 1) {
            return true;
        }

        int f = 0;
        for (int i = k + 1; i < ssize(nums); i++) {
            win.erase(nums[f]);

            if (win.contains(nums[i])) {
                return true;
            }

            win.insert(nums[i]);
            f++;
        }

        return false;
    }
};

int main() {
    vector<int> v = {1};

    Solution s;
    bool res = s.containsNearbyDuplicate(v, 1);

    return 0;
}