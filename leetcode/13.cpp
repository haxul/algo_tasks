#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  int romanToInt(string s) {
    int n = s.length();
    int ret = 0;

    for (int i = n - 1; i >= 0; i--) {
      char prev = (i == n - 1) ? 'K' : s[i + 1];
      char cur = s[i];

      switch (cur) {
      case 'I':
        if (prev == 'V' || prev == 'X') {
          ret -= 1;
        } else {
          ret += 1;
        }
        break;
      case 'V':
        ret += 5;
        break;
      case 'X':
        if (prev == 'L' || prev == 'C') {
          ret -= 10;
        } else {
          ret += 10;
        }
        break;
      case 'L':
        ret += 50;
        break;
      case 'C':
        if (prev == 'D' || prev == 'M') {
          ret -= 100;
        } else {
          ret += 100;
        }
        break;
      case 'D':
        ret += 500;
        break;
      case 'M':
        ret += 1000;
        break;
      }
    }

    return ret;
  }
};

int main() {

  Solution s;
  cout << s.romanToInt("MCMXCIV") << endl;
  return 0;
}