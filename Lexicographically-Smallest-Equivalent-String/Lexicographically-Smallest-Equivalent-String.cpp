class Solution {
public:
    int charToInt(char chr) {
        return chr - 'a';
    }
    char intToChar(int num) {
        return num + 'a';
    }
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
            graph[charToInt(s1[i])].push_back(charToInt(s2[i]));
            graph[charToInt(s2[i])].push_back(charToInt(s1[i]));
        }
        map&lt;char, char&gt; dp;
        vector&lt;bool&gt; visited(26);
        string result;
        for (auto chr : baseStr) {
            fill(visited.begin(), visited.end(), false);
            int start = charToInt(chr);
            visited[start] = true;
            if (dp.find(chr) != dp.end()) result.push_back(dp[chr]);
            else {
                char tmp = intToChar(dfs(graph, start, visited));
                dp[chr] = tmp;
                result.push_back(tmp);
            }
        }
        return result;
    }
};