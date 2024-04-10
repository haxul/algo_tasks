#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r)  / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m; 
            }
        }
        return l; 
    }
};
