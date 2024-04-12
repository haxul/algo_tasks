#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        int prev = 0, cur = 1, ret = 0;
        while (n >= 0) {
            ret = prev + cur;
            prev = cur;
            cur = ret;
            n--;
        }

        return ret;
    }
};
