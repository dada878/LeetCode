class Solution {
public:
    int ans = -1;
    void dfs(vector&lt;int&gt;&amp; edges, unordered_map&lt;int, int&gt;&amp; dist, vector&lt;bool&gt;&amp; visited, int vertex, int step) {
        // cout &lt;&lt; "visit : " &lt;&lt; vertex &lt;&lt; endl;
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
            // cout &lt;&lt; "check visit " &lt;&lt; i &lt;&lt; " : " &lt;&lt; visited[i] &lt;&lt; endl;
            if (visited[i]) continue;
            unordered_map&lt;int, int&gt; dist;
            dfs(edges, dist, visited, i, 1);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int answer = -1;
//     void dfs(int node, vector&lt;int&gt;&amp; edges, unordered_map&lt;int, int&gt;&amp; dist, vector&lt;bool&gt;&amp; visit) {
//         cout &lt;&lt; "visit : " &lt;&lt; node &lt;&lt; endl;
//         visit[node] = true;
//         int neighbor = edges[node];
//         if (neighbor != -1 &amp;&amp; !visit[neighbor]) {
//             dist[neighbor] = dist[node] + 1;
//             dfs(neighbor, edges, dist, visit);
//         } else if (neighbor != -1 &amp;&amp; dist.count(neighbor)) {
//             answer = max(answer, dist[node] - dist[neighbor] + 1);
//         }
//     }
//     int longestCycle(vector&lt;int&gt;&amp; edges) {
//         int n = edges.size();
//         vector&lt;bool&gt; visit(n);
//         for (int i = 0; i &lt; n; i++) {
//             if (!visit[i]) {
//                 unordered_map&lt;int, int&gt; dist;
//                 dist[i] = 1;
//                 dfs(i, edges, dist, visit);
//             }
//         }
//         return answer;
//     }
// };