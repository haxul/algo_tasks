#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-101);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        } 

        return dummy.next;
    }
};