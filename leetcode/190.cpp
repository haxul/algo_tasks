#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rb, mask = 1, ret = 0;

        for (uint32_t i = 0; i < 32; i++) {
            ret = ret << 1;
            rb = (mask << i) & n;
            if (rb) {
                ret = ret | 1;
            }
        }
        return ret;
    }
};
