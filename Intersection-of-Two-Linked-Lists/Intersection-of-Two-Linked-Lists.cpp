/**
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map&lt;ListNode*, ListNode*&gt; table;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != NULL) {
            table[p1] = p1;
            p1 = p1-&gt;next;
        }
        while (p2 != NULL) {
            if (table[p2] != NULL) return p2;
            table[p2] = p2;
            p2 = p2-&gt;next;
        }
        return NULL;
    }
};