class Solution(object):
    def maxPathSum(self, root):
        """
        """
        self.msum = float('-inf')
        self.get_sum(root)
        return self.msum
    def get_sum(self, node):
        if not node:
            return 0
        ls, rs = self.get_sum(node.left), self.get_sum(node.right)
        max_single_path = max(node.val+max(ls,rs), node.val)
        self.msum = max(self.msum, max_single_path , node.val+ls+rs)
        return max_single_path