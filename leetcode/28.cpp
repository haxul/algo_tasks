#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;
class Solution {
public:

    bool cmp(string& h, string& d, int i) {
        if (i + d.size() > h.size()) return false;
        int p = 0;
        for (int j = i; j < i + d.size(); j++) {
           if (h[j] != d[p]) {
              return false;
           } else {
              p++;
           }
        }

        return true;
        
    }
    int strStr(string haystack, string needle) {
        int i = 0;
        int p = 0;

        for (int i = 0; i < haystack.size(); i++) {
           if (cmp(haystack, needle, i)) {
            return i;
           } 
        }
         
        return -1;
    }
};

int main() {
    string haystack = "mississippi", needle = "issip";
    Solution s;
    int ret = s.strStr(haystack, needle);
    return 0;
}