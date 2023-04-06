int dx[4] {0, 1, 0, -1};
int dy[4] {1, 0, -1, 0};
class Solution {
public:
    void dfs(vector&lt;vector&lt;int&gt;&gt;&amp; grid, int x, int y, bool&amp; valid) {
        grid[x][y] = 1;
        for (int i = 0; i &lt; 4; i++) {
            for (int j = 0; j &lt; 4; j++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx &lt; 0 || ny &lt; 0 || nx &gt;= grid.size() || ny &gt;= grid[0].size()) {
                    valid = false;
                    continue;
                }
                if (grid[nx][ny] == 1) continue;
                dfs(grid, nx, ny, valid);
            }
        }
    }
    int closedIsland(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {
        int ans = 0;
        for (int i = 0; i &lt; grid.size(); i++) {
            for (int j = 0; j &lt; grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    bool valid = true;
                    dfs(grid, i, j, valid);
                    ans += valid;
                }
            }
        }
        return ans;
    }
};