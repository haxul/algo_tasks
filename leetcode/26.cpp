#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int r = 1, n = nums.size();
    for (int w = 1; w < n; w++) {
      if (nums[w - 1] != nums[w]) {
        nums[r] = nums[w];
        r++;
      }
    }

    return r;
  }
};

int main() {
    vector<int> v = {0, 0, 0, 1, 1, 2, 2,2, 3};
    Solution s;
    cout << s.removeDuplicates(v) << endl;
    return 0;
}