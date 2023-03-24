class Solution {
public:
    void dfs(vector&lt;vector&lt;pair&lt;int, bool&gt;&gt;&gt;&amp; graph, vector&lt;bool&gt;&amp; visited, int vertex, int &amp;ans) {
        visited[vertex] = true;
        for (auto edge : graph[vertex]) {
            if (visited[edge.first]) continue;
            if (!edge.second) ans++, edge.second = true;
            visited[edge.first] = true;
            dfs(graph, visited, edge.first, ans);
        }
    }
    int minReorder(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {
        vector&lt;vector&lt;pair&lt;int, bool&gt;&gt;&gt; graph(n);
        for (auto connection : connections) {
            graph[connection[0]].push_back({connection[1], false});
            graph[connection[1]].push_back({connection[0], true});
        }
        vector&lt;bool&gt; visited(n);
        int ans = 0;
        dfs(graph, visited, 0, ans);
        return ans;
    }
};