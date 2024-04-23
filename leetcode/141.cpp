#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "tree_node.cpp"

using namespace std;

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>  set;

        ListNode* cur = head;

        while (cur != nullptr) {
            if (set.contains(cur)) {
                return true;
            }
            set.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};


int main() {
    vector<int> v = {3,2,0,-4};
    ListNode* head = buildLL(v);
    head->next->next->next->next = head->next;

    Solution s;
    s.hasCycle(head);

    return 0;
}