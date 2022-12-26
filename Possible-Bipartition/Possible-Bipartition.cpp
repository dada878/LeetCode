class Solution {
public:
    void dfs(
        vector&lt;vector&lt;int&gt;&gt; &amp;graph,
        vector&lt;bool&gt; &amp;visited,
        vector&lt;int&gt;&amp; color,
        int val,
        bool&amp; result
    ) {
        // cout &lt;&lt; val &lt;&lt; endl;
        vector&lt;int&gt; edge = graph[val];
        for (int i = 0; i &lt; edge.size(); i++) {
            if (!visited[edge[i]]) {
                visited[edge[i]] = true;
                color[edge[i]] = color[val] == 1 ? 2 : 1;
                dfs(graph, visited, color, edge[i], result);
            } else if (color[edge[i]] == color[val]) {
                result = false;
            }
        }
    }
    bool possibleBipartition(int n, vector&lt;vector&lt;int&gt;&gt;&amp; dislikes) {
        if (n &lt;= 1) return true;
        vector&lt;vector&lt;int&gt;&gt; graph(n + 1);
        vector&lt;bool&gt; visited(n + 1);
        vector&lt;int&gt; color(n + 1);
        for (int i = 0; i &lt; dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool result = true;
        for (int i = 1; i &lt;= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                color[i] = 1;
                dfs(graph, visited, color, i, result);
            }
        }
        return result;
    }
};