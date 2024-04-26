#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./tree_node.cpp"

using namespace std;



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;

        ListNode* cur = headA;

        while(cur != nullptr) {
            set.insert(cur);
            cur= cur->next;
        }

        cur = headB;

        while(cur!=nullptr) {
            if (set.contains(cur)) {
                return cur;
            }
            cur = cur->next;
        }

        return nullptr;
    }
};