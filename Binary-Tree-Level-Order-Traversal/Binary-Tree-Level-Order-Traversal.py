# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def traversal(node, depth=0, result=[]):
    print(result)
    if node == None: return
    if len(result) &lt; depth+1:
        result.append([])
    traversal(node.left, depth=depth+1, result=result)
    traversal(node.right, depth=depth+1, result=result)
    result[depth].append(node.val)
    print(result)
    return result
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -&gt; List[List[int]]:
        return traversal(root, result=[])