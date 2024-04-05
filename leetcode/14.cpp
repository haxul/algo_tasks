#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string* first = &strs[0];
    int ptr = 0;
    while (ptr < first->size()) {

      for (int i = 1; i < strs.size(); ++i) {
        string* cur = &strs[i];
        if ((*cur)[ptr] != (*first)[ptr]) {
          return first->substr(0, ptr);
        }
      }
        ptr++;
    }

    return first->substr(0, ptr);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> v = {"flower", "flow", "flight"};
  cout << s.longestCommonPrefix(v) << endl;

  return 0;
}
