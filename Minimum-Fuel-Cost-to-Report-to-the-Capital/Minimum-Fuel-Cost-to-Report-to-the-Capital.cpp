class Solution {
 public:
  long long minimumFuelCost(vector&lt;vector&lt;int&gt;&gt;&amp; roads, int seats) {
    long long ans = 0;
    vector&lt;vector&lt;int&gt;&gt; graph(roads.size() + 1);
    for (const vector&lt;int&gt;&amp; road : roads) {
      const int u = road[0];
      const int v = road[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    dfs(graph, 0, -1, seats, ans);
    return ans;
  }
 private:
  int dfs(const vector&lt;vector&lt;int&gt;&gt;&amp; graph, int u, int prev, int seats,
          long long&amp; ans) {
    int people = 1;
    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      people += dfs(graph, v, u, seats, ans);
    }
    if (u &gt; 0)
      // # of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
  }
};