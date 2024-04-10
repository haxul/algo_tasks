#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string& less = a.size() > b.size() ? b : a;
        string& great = a == less ? b : a; 

        int n = great.size(); 
        string padding(great.size() - less.size(), '0'); 

        less = padding +  less;

        string ret(n, '0');
        int carry = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int a = (less[i] - '0') + (great[i] - '0') + carry;
            if (a == 2) {
                ret[i] = '0';
                carry = 1;
            } else if (a == 1) {
                ret[i] = '1';
                carry  = 0;
            } else if (a== 0){
                ret[i] = '0';
                carry = 0;
            } else if (a == 3) {
                ret[i] = '1';
                carry = 1;
            }
        }

        if (carry == 1) {
            return "1" + ret;
        } 
        return ret;       
    }
};


int main() {
    Solution s;

    cout << s.addBinary("1111", "1111") << endl;
}


