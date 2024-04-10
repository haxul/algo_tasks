#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.size() - 1;

        while (p >= 0 && s[p] == ' ') {
            p--;
        }
        int ret = 0;

        while (p >= 0 && s[p] != ' ') {
            ret++;
            p--;
        }


        return ret;
               
    }
};