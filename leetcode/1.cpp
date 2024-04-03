#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int d = target - nums[i];

      if (m.contains(d)) {
        return {i, m[d]};
      } else {
        m[nums[i]] = i;
      }
    }

    return {-1, -1};
  }
};

int main() {
  Solution s;
  vector<int> v{3, 2, 4};
  auto ret = s.twoSum(v, 6);
  for (int i = 0; i < ret.size(); ++i) {
    cout << ret[i] << endl;
  }

  return 0;
}
