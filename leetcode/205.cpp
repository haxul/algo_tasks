#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = ssize(s);
        unordered_map<char, char> sm;
        unordered_map<char, char> tm;

        for (int i = 0; i < n; i++) {
            sm[s[i]] = t[i];
            tm[t[i]] = s[i];
        }

        if (ssize(sm) != ssize(tm)) {
            return false;
        }


        for (int i = 0; i < n; i++)
        {
            if (sm[s[i]] != t[i]) {
                return false;
            }

            if (tm[t[i]]  != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};
