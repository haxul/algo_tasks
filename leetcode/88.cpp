#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = ssize(nums1) - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        while (p >= 0 && p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        while (p >= 0 && p1 >= 0) {
            nums1[p] = nums1[p1];
            p1--;
            p--;
        }

        while (p >= 0 && p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};