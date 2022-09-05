"Link: https://leetcode.com/problems/palindrome-linked-list/";
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        array = []
        node = head
        while node != None:
            array.append(node.val)
            node = node.next
        for i in range(len(array)//2):
            if array[i] != array[-i-1]:
                return False
        return True