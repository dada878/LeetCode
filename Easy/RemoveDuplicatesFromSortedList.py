"Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/"

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        ls = []
        p = head
        while p:
            ls.append(p.val)
            p = p.next
        ls = list(set(ls))
        ls.sort()
        root = ListNode(ls[0])
        p = root
        for i in ls[1:]:
            temp = ListNode(i)
            p.next = temp
            p = p.next
        return root
