#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = ssize(s) - 1;

        while (l < r) {
            while (l < r && !iswalnum(s[l])) {
                l++;
            }

            while (l < r && !iswalnum(s[r])) {
                r--;
            }

            if (l == r) {
                return true;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            r--;
            l++;
        }

        return true;
    }
};


int main() {
    Solution s;

   auto a =  s.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}