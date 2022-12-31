class Solution {
    // Dimensions 
    int m, n;
    // Direction Vectors
    vector&lt;int&gt; dx = {-1, 1, 0, 0};
    vector&lt;int&gt; dy = {0, 0, -1, 1};
public:
    // function to check for the validity of CELLij
    bool isvalid(int i, int j)
    {
        return i &gt;= 0 and j &gt;= 0 and i &lt; m and j &lt; n;
    }
    int dfs(int i, int j, int left, pair&lt;int, int&gt; dest, vector&lt;vector&lt;int&gt;&gt; &amp;grid)
    {
        // Base case
        if (left == -1 and pair&lt;int, int&gt;(i, j) == dest)
            return 1;
        // Mark visited
        grid[i][j] = -1;
        int ans = 0;
        for (int k = 0; k &lt; 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            // Add up all possibilities to answer
            if (isvalid(x, y) and grid[x][y] != -1)
                ans += dfs(x, y, left - 1, dest, grid);
        }
        // Backtrack
        grid[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector&lt;vector&lt;int&gt;&gt; &amp;grid)
    {
        m = grid.size(), n = grid[0].size();
        pair&lt;int, int&gt; src, dest;
        int empty = 0;
        for (int i = 0; i &lt; m; i++)
        {
            for (int j = 0; j &lt; n; j++)
            {
                if (grid[i][j] == 0)
                    empty++;
                if (grid[i][j] == 1)
                    src = {i, j};
                if (grid[i][j] == 2)
                    dest = {i, j};
            }
        }
        return dfs(src.first, src.second, empty, dest, grid);
    }
};