class Solution {
public:
    void dfs(
        vector&lt;vector&lt;int&gt;&gt;&amp; graph,
        vector&lt;int&gt;&amp; edge,
        vector&lt;bool&gt;&amp; visited,
        int&amp; target,
        bool&amp; result
    ) {
        for (int i = 0; i &lt; edge.size(); i++) {
            if (result) return;
            if (!visited[edge[i]]) {
                if (edge[i] == target) {
                    result = true;
                }
                visited[edge[i]] = true;
                dfs(graph, graph[edge[i]], visited, target, result);
            }
        }
    }
    bool validPath(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int source, int destination) {
        if (source == destination) return true;
        vector&lt;vector&lt;int&gt;&gt; graph(n);
        vector&lt;bool&gt; visited(n);
        bool result = false;
        for(auto&amp; edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(graph, graph[source], visited, destination, result);
        return result;
    }
};