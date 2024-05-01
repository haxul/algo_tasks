
#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = 1;
        int t = ssize(nums) / 2 +1;
        for (int i = 1; i < ssize(nums); i++) {
            if (nums[i - 1] == nums[i]) {
                n++;
            } else {
                n = 1;
            }

            if (n == t) {
                return nums[i];
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v = {2,2,1,1,1,2,2};
    s.majorityElement(v);
    return 0;
}