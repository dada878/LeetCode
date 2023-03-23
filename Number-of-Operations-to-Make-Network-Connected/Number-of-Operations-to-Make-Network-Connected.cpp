class Solution {
    void dfs(vector&lt;int&gt; adj[], vector&lt;bool&gt; &amp;visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
public:
    int makeConnected(int n, vector&lt;vector&lt;int&gt;&gt;&amp; arr) {
        int len = arr.size();
        if(len&lt;n-1) return -1;
         vector&lt;int&gt; adj[n];
        for(auto v : arr)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector&lt;bool&gt; visited(n, false);
        int ans = 0;
        for(int i=0; i&lt;n; i++)
        if(!visited[i])
        {
            dfs(adj, visited, i);
            ans++;
        }
        return ans - 1;
    }
};
