class Solution {
public:
    bool canJump(vector&lt;int&gt;&amp; nums) {
        if (nums.size() == 1) return true;
        vector&lt;int&gt; dp(nums.size()-1);
        dp[0] = 0;
        for (int i = 0; i &lt; nums.size()-1; i++) {
            dp[i] = max(dp[max(i-1, 0)]-1, nums[i]);
            if (dp[i] == 0) return false;
        }
        return true;
    }
};