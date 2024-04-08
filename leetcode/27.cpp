#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    if (n == 0) return 0;
    int l = 0, r = n - 1;


    while (nums[r] == val) {
        r--;
        if (r == -1) break;
    }
      ;
    while (l < r) {

      if (nums[l] == val) {
        nums[l] = nums[r];
        nums[r] = val;
      }

      while (nums[r] == val) {
        r--;
      }
        ;
        l++;
    }

    while (l < n && nums[l] != val) {
        l ++;
    }
    return l;
  }
};

int main() {
   vector<int> v = {3,2,2,3};
   Solution s;
   int res = s.removeElement(v, 3);

   return 0;
}