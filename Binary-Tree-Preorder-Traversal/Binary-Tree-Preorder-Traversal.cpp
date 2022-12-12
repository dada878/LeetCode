/**
 */
class Solution {
public:
    void dfs(TreeNode* node, vector&lt;int&gt; &amp;result) {
        if (node == NULL) return;
        result.push_back(node-&gt;val);
        dfs(node-&gt;left, result);
        dfs(node-&gt;right, result);
    }
    vector&lt;int&gt; preorderTraversal(TreeNode* root) {
        vector&lt;int&gt; result;
        dfs(root, result);
        return result;
    }
};