#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        ret[0] = {1};
        if (numRows == 1) {
            return ret;
        }
        ret[1] = {1, 1};
        if (numRows == 2) {
            return ret;
        }
        int s = 2;
        while (s < numRows) {
            ret[s].reserve(s + 1);
            ret[s].push_back(1);
            for (int i = 0; i < ssize(ret[s - 1]) - 1; i++) {
                ret[s].push_back(ret[s - 1][i] + ret[s - 1][i + 1]);
            }
            ret[s].push_back(1);
            s++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    auto r = s.generate(5);
    return 0;
}