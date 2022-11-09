// https://leetcode.com/problems/linked-list-cycle/description/
#include <iostream>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *m = head;
        ListNode *n = head;
        while (true) {
            if (n != NULL && n->next != NULL) {
                n = n->next;
            } else break;
            if (m != NULL && m->next != NULL && m->next->next != NULL) {
                m = m->next->next;
            } else break;
            if (&n->val == &m->val) {
                return true;
            }
        }
        return false;
    }
};