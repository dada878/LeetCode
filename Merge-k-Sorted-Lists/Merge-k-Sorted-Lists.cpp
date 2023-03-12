class Solution {
public:
    ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKListsHelper(vector&lt;ListNode*&gt;&amp; lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 &amp;&amp; l2) {
            if (l1-&gt;val &lt; l2-&gt;val) {
                curr-&gt;next = l1;
                l1 = l1-&gt;next;
            } else {
                curr-&gt;next = l2;
                l2 = l2-&gt;next;
            }
            curr = curr-&gt;next;
        }
        curr-&gt;next = l1 ? l1 : l2;
        return dummy-&gt;next;
    }
};