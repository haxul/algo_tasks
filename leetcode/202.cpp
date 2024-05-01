#include <unordered_set>

using namespace std;
class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while (true) {
            n = ss(n);
            if (set.contains(n)) {
                break;
            }
            set.insert(n);
        }

        return n == 1;
    }

    int ss(int n) {
        int ret = 0;
        int last;
        while (n > 0) {
            last = n % 10;
            ret += (last * last);
            n /= 10;
        }

        return ret;
    }
};