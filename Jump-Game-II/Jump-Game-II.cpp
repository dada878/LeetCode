class Solution {
public:
    int jump(vector&lt;int&gt;&amp; nums) {
        vector&lt;int&gt; dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i &lt; nums.size(); i++) {
            for (int j = 1; j &lt;= nums[i] &amp;&amp; i + j &lt; nums.size(); j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[nums.size()-1];
    }
};