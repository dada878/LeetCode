"Link: https://leetcode.com/problems/balanced-binary-tree"

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(node):
            if not node: return [True, 0]
            right, left = dfs(node.right), dfs(node.left)
            balanced = left[0] and right[0] and abs(right[1] - left[1]) <= 1
            return [balanced, max(right[1], left[1])+1]
        return dfs(root)[0]