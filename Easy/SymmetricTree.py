"Link: https://leetcode.com/problems/symmetric-tree"
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def treeToString(root, reverse):
    if not root:
        return None
    if not root.left and not root.right:
        return root.val
    if reverse:
        return f"{root.val}({treeToString(root.right, reverse)})({treeToString(root.left, reverse)})"
    else:
        return f"{root.val}({treeToString(root.left, reverse)})({treeToString(root.right, reverse)})"


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return treeToString(root.left, False) == treeToString(root.right, True)
