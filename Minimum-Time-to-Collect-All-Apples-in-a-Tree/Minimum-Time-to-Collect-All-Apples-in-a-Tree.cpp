class Solution {
public:
    bool dfs(vector&lt;vector&lt;int&gt;&gt;&amp; graph, vector&lt;bool&gt;&amp; apples, int vertex, int&amp; counter, vector&lt;bool&gt; visited) {
        bool hasApple = apples[vertex];
        vector&lt;int&gt; edges = graph[vertex];
        for (int i = 0; i &lt; edges.size(); i++) {
            if (!visited[edges[i]]) {
                visited[edges[i]] = true;
                hasApple = (dfs(graph, apples, edges[i], counter, visited) || hasApple);
            }
        }
        // cout &lt;&lt; vertex &lt;&lt; " : " &lt;&lt; hasApple &lt;&lt; endl;
        counter += hasApple;
        return hasApple;
    }
    int minTime(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, vector&lt;bool&gt;&amp; apples) {
        vector&lt;vector&lt;int&gt;&gt; graph(n);
        vector&lt;bool&gt; visited(n);
        for (int i = 0; i &lt; edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int counter = 0;
        visited[0] = true;
        dfs(graph, apples, 0, counter, visited);
        return max(0, (counter - 1) * 2);
    }
};