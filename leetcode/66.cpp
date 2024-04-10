
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> ret;

    int carry = 0;
    int n = digits.size();
    digits[n - 1] = digits[n - 1] + 1;
    reverse(digits.begin(), digits.end());
    for (auto d : digits) {
      ret.push_back(d + carry);
      if (ret[ret.size() - 1] == 10) {
        ret[ret.size() - 1] = 0;
        carry = 1;
      } else {
        carry = 0;
      }
    }

    if (carry == 1) {
      ret.push_back(1);
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution s;
  vector<int> v = {9, 9};

  auto r = s.plusOne(v);

  for (auto a : r) {
    cout << a << endl;
  }
  return 0;
}