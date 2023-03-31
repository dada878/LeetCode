class Solution {
public:
    int ways(vector&lt;string&gt;&amp; pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt; dp(vector(k, vector(m, vector(n, -1))));
        vector&lt;vector&lt;int&gt;&gt; preSum(vector(m+1, vector(n+1, 0)));
        for (int r = m - 1; r &gt;= 0; r--)
            for (int c = n - 1; c &gt;= 0; c--)
                preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A');
        return dfs(m, n, k-1, 0, 0, dp, preSum);
    }
    int dfs(int m, int n, int k, int r, int c, vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt;&amp; dp, vector&lt;vector&lt;int&gt;&gt;&amp; preSum) {
        if (preSum[r][c] == 0) return 0; 
        if (k == 0) return 1; 
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;
        for (int nr = r + 1; nr &lt; m; nr++) 
            if (preSum[r][c] - preSum[nr][c] &gt; 0)
                ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;
        for (int nc = c + 1; nc &lt; n; nc++) 
            if (preSum[r][c] - preSum[r][nc] &gt; 0)
                ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007;
        return dp[k][r][c] = ans;
    }
};