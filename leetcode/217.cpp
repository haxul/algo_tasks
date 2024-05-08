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
};