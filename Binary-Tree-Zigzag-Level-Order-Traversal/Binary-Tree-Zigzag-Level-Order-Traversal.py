# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def traversal(node, depth=0, result=[]):
    if node == None:
        return
    if len(result) &lt; depth+1:
        result.append([])
    traversal(node.left, depth=depth+1, result=result)
    traversal(node.right, depth=depth+1, result=result)
    result[depth].append(node.val)
    return result
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -&gt; List[List[int]]:
        if root == None: return None
        result = traversal(root, result=[])
        for i in range(len(result)):
            if i % 2 == 1:
                result[i].reverse()
        return result