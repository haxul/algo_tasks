#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, l = 0, r = 0;
        int n = ssize(prices);

        while (r < n) {
            if (prices[l] > prices[r]) {
                l = r;
            }

            ret = max(ret, prices[r] - prices[l]);
            r++;
        }

        ret = max(ret, prices[n - 1] - prices[l]);

        return ret;
    }
};

int main() {
    Solution s;

    vector<int> v = {7, 1, 5, 3, 6, 4};
    s.maxProfit(v);

    return 0;
}