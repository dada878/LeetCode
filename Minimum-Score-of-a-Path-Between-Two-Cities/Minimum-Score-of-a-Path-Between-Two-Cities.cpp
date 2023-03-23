class Solution {
public:
    int dfs(int node,int&amp; ans, vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt;&amp; gr, vector&lt;int&gt;&amp; vis){
        vis[node] = 1;
        for(auto&amp; [v, dis] : gr[node]){
            ans = min(ans, dis);
            if(vis[v]==0){
                vis[v] = 1;
                ans = min(ans, dfs(v, ans, gr, vis));
            }
        }
        return ans;
    }
    int minScore(int n, vector&lt;vector&lt;int&gt;&gt;&amp; roads) {
        int ans = INT_MAX;
        vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; gr(n+1);
        for(auto edge : roads){ 
            gr[edge[0]].push_back({edge[1], edge[2]}); // u-&gt; {v, dis}
            gr[edge[1]].push_back({edge[0], edge[2]}); // v-&gt; {u, dis}
        }
        vector&lt;int&gt; vis(n+1, 0);
        dfs(1, ans, gr, vis);
        return ans;
    }
};