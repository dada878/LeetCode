class Solution {
public:
  vector&lt;int&gt; fun(vector&lt;vector&lt;int&gt;&gt; &amp;adj, string &amp;labels, int i,vector&lt;int&gt;&amp;result){
    vector&lt;int&gt; ans(26, 0);
    result[i] = 1;
    ans[labels[i] - 'a'] = 1;
    for(int j = 0; j != adj[i].size(); j++)
      if(!result[adj[i][j]]){
        vector&lt;int&gt; tmp = fun(adj, labels,adj[i][j],result);
        for(int k = 0; k != 26; k++) ans[k] += tmp[k];
      }
    result[i] = ans[labels[i] - 'a'];
    return ans;
  }
  vector&lt;int&gt; countSubTrees(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, string labels) {
    vector&lt;vector&lt;int&gt;&gt; adj(n);
    vector&lt;int&gt; result(n,0);
    for(int i = 0; i != edges.size(); i++)
     {adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
     }
    fun(adj, labels, 0,result);
    return result;
  }
};