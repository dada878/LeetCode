/**
 */
class Solution {
public:
    void dfs(TreeNode* node, int maxVal, int minVal, int &amp;result) {
        if (node == NULL) return;
        maxVal = max(maxVal, node-&gt;val);
        minVal = min(minVal, node-&gt;val);
        if (node-&gt;left == NULL &amp;&amp; node-&gt;right == NULL) {
            result = max(result, maxVal - minVal);
        } else {
            dfs(node-&gt;left, maxVal, minVal, result);
            dfs(node-&gt;right, maxVal, minVal, result);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, INT_MIN, INT_MAX, result);
        return result;
    }
};