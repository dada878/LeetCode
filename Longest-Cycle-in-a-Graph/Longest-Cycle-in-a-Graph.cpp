class Solution {
public:
    int ans = -1;
    void dfs(vector&lt;int&gt;&amp; edges, unordered_map&lt;int, int&gt;&amp; dist, vector&lt;bool&gt;&amp; visited, int vertex, int step) {
        visited[vertex] = true;
        dist[vertex] = step;
        int next = edges[vertex];
        if (next != -1 &amp;&amp; !visited[next]) {
            dfs(edges, dist, visited, next, step + 1);
        } else if (next != -1 &amp;&amp; dist[next] &gt; 0) {
            ans = max(ans, step - dist[next] + 1);
        }
    }
    int longestCycle(vector&lt;int&gt;&amp; edges) {
        int n = edges.size();
        vector&lt;bool&gt; visited(n);
        for (int i = 0; i &lt; n; i++) {
            if (visited[i]) continue;
            unordered_map&lt;int, int&gt; dist;
            dfs(edges, dist, visited, i, 1);
        }
        return ans;
    }
};