#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < ssize(nums); i++) {
            ret ^= nums[i];
        }

        return ret;
    }
};