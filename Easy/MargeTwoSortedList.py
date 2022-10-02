"Link: https://leetcode.com/problems/merge-two-sorted-lists/description/"
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def walkList(l):
    result = []
    p = l
    while (p != None):
        result.append(p.val)
        p = p.next
    return result


def createLinkedList(array):
    if len(array) == 0:
        return None
    root = ListNode(array[0])
    p = root
    for i in array[1:]:
        temp = ListNode(i)
        p.next = temp
        p = p.next
    return root


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        linkedListValues = []
        linkedListValues.extend(walkList(list1))
        linkedListValues.extend(walkList(list2))
        linkedListValues.sort()
        return createLinkedList(linkedListValues)
