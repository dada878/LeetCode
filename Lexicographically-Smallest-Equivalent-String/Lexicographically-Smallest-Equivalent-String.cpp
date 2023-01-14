class Solution {
public:
    int dfs(vector&lt;vector&lt;int&gt;&gt;&amp; graph, int vertex, vector&lt;bool&gt;&amp; visited) {
        int result = vertex;
        for (auto edge : graph[vertex]) {
            if (!visited[edge]) {
                visited[edge] = true;
                result = min(dfs(graph, edge, visited), result);
            }
        }
        return result;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector&lt;vector&lt;int&gt;&gt; graph(26);
        for (int i = 0; i &lt; s1.length(); i++) {
            graph[s1[i] - 'a'].push_back(s2[i] - 'a');
            graph[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        map&lt;char, char&gt; dp;
        vector&lt;bool&gt; visited(26);
        string result;
        for (auto chr : baseStr) {
            fill(visited.begin(), visited.end(), false);
            int start = chr - 'a';
            visited[start] = true;
            if (dp.find(chr) != dp.end()) result.push_back(dp[chr]);
            else {
                char tmp = dfs(graph, start, visited) + 'a';
                dp[chr] = tmp;
                result.push_back(tmp);
            }
        }
        return result;
    }
};