#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
class Solution {
public:
  int mySqrt(int x) {
    int l = 0, r = x;

    while (l < r) {
      ll m = l + (r - l) / 2;
      ll s1 = m * m;
      ll s2 = (m + 1) * (m + 1);
      if (s1 == x) {
        return m;
      } else if (s1 < x && s2 > x) {
        return m;
      } else if (s1 > x) {
        r = m - 1;
      } else {
        l = m + 1;
      }
   }

    return r;
  }
};

int main() {
  Solution s;
  cout << s.mySqrt(8) << endl;
  return 0;
}
