/**
 */
class Solution {
public:
    void dfs(TreeNode* node, vector&lt;int&gt; &amp;result) {
        if (node == NULL) return;
        dfs(node-&gt;left, result);
        dfs(node-&gt;right, result);
        result.push_back(node-&gt;val);
    }
    vector&lt;int&gt; postorderTraversal(TreeNode* root) {
        vector&lt;int&gt; result;
        dfs(root, result);
        return result;
    }
};