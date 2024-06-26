#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy;
    ListNode *cur = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }

      cur = cur->next;
    }

    while (list1 != nullptr) {
      cur->next = list1;
      cur = cur->next;
      list1 = list1->next;
    }

    while (list2 != nullptr) {
      cur->next = list2;
      cur = cur->next;
      list2 = list2->next;
    }

    return dummy.next;
  }
};
