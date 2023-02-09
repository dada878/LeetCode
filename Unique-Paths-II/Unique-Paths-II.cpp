class Solution {
public:
    int uniquePathsWithObstacles(vector&lt;vector&lt;int&gt;&gt;&amp; map) {
        if (map[0][0] == 1) return 0;
        int m = map.size();
        int n = map[0].size();
        vector&lt;vector&lt;int&gt;&gt; dp(m, vector&lt;int&gt;(n));
        dp[0][0] = 1;
        for (int i = 0; i &lt; m; i++) {
            for (int j = 0; j &lt; n; j++) {
                if (i == 0 &amp;&amp; j == 0) continue;
                if (map[i][j] == 1) continue;
                int v1 = 0, v2 = 0;
                if (i &gt; 0) v1 = dp[i-1][j];
                if (j &gt; 0) v2 = dp[i][j-1];
                dp[i][j] = v1 + v2;
            }
        }
        return dp[m-1][n-1];
    }
};
