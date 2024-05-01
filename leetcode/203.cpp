#include "./tree_node.cpp"

using namespace std;

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur != nullptr) {
            while (cur != nullptr && cur->val == val) {
                cur = cur->next;
            }
            prev->next = cur;
            prev = prev->next;

            if (cur == nullptr) {
                return dummy.next;
            }
            cur = cur->next;
        }

        return dummy.next;
    }
};