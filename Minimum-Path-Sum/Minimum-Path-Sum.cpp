class Solution {
public:
    int minPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        vector&lt;vector&lt;int&gt;&gt; dp(m, vector&lt;int&gt;(n));
        for (int i = 0; i &lt; m; i++) {
            for (int j = 0; j &lt; n; j++) {
                if (i == 0 &amp;&amp; j == 0) {
                    dp[j][i] = grid[i][j];
                } else if (i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};