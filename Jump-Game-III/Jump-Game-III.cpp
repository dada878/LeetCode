class Solution {
public:
    vector&lt;bool&gt; visited;
    bool reached = false;
    void dfs(int index, vector&lt;int&gt;&amp; arr) {
        if (reached || visited[index]) return;
        visited[index] = true;
        if (arr[index] == 0) reached = true;
        if (index - arr[index] &gt;= 0) dfs(index - arr[index], arr);
        if (index + arr[index] &lt; arr.size()) dfs(index + arr[index], arr);
    }
    bool canReach(vector&lt;int&gt;&amp; arr, int start) {
        visited.resize(arr.size());
        dfs(start, arr);
        return reached;
    }
};