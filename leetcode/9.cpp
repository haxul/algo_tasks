#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    if (x < 10)
      return true;
    ll n = x;
    ll r = 0;

    while (n != 0) {
      r = r * 10 + (n % 10);
      n = n / 10;
    }

    return r == x;
  }
};

int main() {
  Solution s;
  auto r = s.isPalindrome(1234567899);
  cout << r << endl;
  return 0;
}
