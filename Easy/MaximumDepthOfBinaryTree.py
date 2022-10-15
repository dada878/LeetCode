"Link: https://leetcode.com/problems/maximum-depth-of-binary-tree"

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def traversal(node, depth=1):
    if node == None:
        return depth-1
    return max(traversal(node.left, depth=depth+1), traversal(node.right, depth=depth+1))


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return traversal(root)
