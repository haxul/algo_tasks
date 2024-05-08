#include "./tree_node.cpp"

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = nullptr;
        ListNode* cur = head;
        ListNode* t;
        while (cur != nullptr) {
            t = cur;
            cur = cur->next;
            t->next = dummy.next;
            dummy.next = t;
        }


        return dummy.next;
    }
};

int main() {
    vector<int> v = {1,2,3,4,5};
    auto list = buildLL(v); 

    Solution s;
    auto res = s.reverseList(list);
    return 0;
}