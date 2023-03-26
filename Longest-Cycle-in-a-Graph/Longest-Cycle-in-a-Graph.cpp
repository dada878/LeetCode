// class Solution {
// public:
//     int dfs(vector&lt;int&gt;&amp; edges, vector&lt;int&gt;&amp; stepper, vector&lt;bool&gt;&amp; visited, int vertex, int step) {
//         visited[vertex] = true;
//         if (edges[vertex] == -1) return 0;
//         if (stepper[vertex] &gt; 0) return step - stepper[vertex];
//         stepper[vertex] = step;
//         return dfs(edges, stepper, visited, edges[vertex], step + 1);
//     }
//     int longestCycle(vector&lt;int&gt;&amp; edges) {
//         int n = edges.size();
//         int ans = 0;
//         vector&lt;bool&gt; visited(n);
//         for (int i = 0; i &lt; n; i++) {
//             if (visited[i]) continue;
//             vector&lt;int&gt; stepper(n);
//             ans = max(ans, dfs(edges, stepper, visited, i, 1));
//         }
//         return ans == 0 ? -1 : ans;
//     }
// };
class Solution {
public:
    int answer = -1;
    void dfs(int node, vector&lt;int&gt;&amp; edges, unordered_map&lt;int, int&gt;&amp; dist, vector&lt;bool&gt;&amp; visit) {
        visit[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 &amp;&amp; !visit[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, visit);
        } else if (neighbor != -1 &amp;&amp; dist.count(neighbor)) {
            answer = max(answer, dist[node] - dist[neighbor] + 1);
        }
    }
    int longestCycle(vector&lt;int&gt;&amp; edges) {
        int n = edges.size();
        vector&lt;bool&gt; visit(n);
        for (int i = 0; i &lt; n; i++) {
            if (!visit[i]) {
                unordered_map&lt;int, int&gt; dist;
                dist[i] = 1;
                dfs(i, edges, dist, visit);
            }
        }
        return answer;
    }
};