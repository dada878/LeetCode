/**
 */
class Solution {
public:
    void dfs(TreeNode* node, vector&lt;int&gt; &amp;nums) {
        if (!node) return;
        dfs(node-&gt;left, nums);
        nums.push_back(node-&gt;val);
        dfs(node-&gt;right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector&lt;int&gt; nums;
        dfs(root, nums);
        unordered_map&lt;int, bool&gt; table;
        for (int i = 0; i &lt; nums.size(); i++) {
            if (table[nums[i]]) return true;
            table[k - nums[i]] = true;
        }
        return false;
    }
};