/**
 */
class Solution {
public:
    void dfs(TreeNode* node, vector&lt;int&gt; &amp;leafs) {
        if (node == NULL) return;
        else if (node-&gt;left == NULL &amp;&amp; node-&gt;right == NULL) {
            leafs.push_back(node-&gt;val);
        } else {
            dfs(node-&gt;left, leafs);
            dfs(node-&gt;right, leafs);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector&lt;int&gt; r1;
        vector&lt;int&gt; r2;
        dfs(root1, r1);
        dfs(root2, r2);
        if (r1.size() != r2.size()) return false;
        for (int i = 0; i &lt; r1.size(); i++) {
            if (r1[i] != r2[i]) return false;
        }
        return true;
    }
};