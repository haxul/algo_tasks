#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (stack.empty()) {
            stack.push(s[i]);
        } else {
            char t = stack.top();
            if (t  == '(' && s[i] == ')') {
                stack.pop();
            } else if (t == '[' && s[i] == ']') {
                stack.pop();
            } else if (t == '{' && s[i] == '}') {
                stack.pop();
            } else {
                stack.push(s[i]);
            }

        }
    }

    return stack.empty();        
  }
};