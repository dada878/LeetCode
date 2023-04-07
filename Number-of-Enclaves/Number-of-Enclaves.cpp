class Solution {
public:
    void dfs(vector&lt;vector&lt;int&gt;&gt;&amp; A, int i, int j) {
  if (i &lt; 0 || j &lt; 0 || i == A.size() || j == A[i].size() || A[i][j] != 1) return;
  A[i][j] = 0;
  dfs(A, i + 1, j), dfs(A, i - 1, j), dfs(A, i, j + 1), dfs(A, i, j - 1);
}
int numEnclaves(vector&lt;vector&lt;int&gt;&gt;&amp; A) {
  for (auto i = 0; i &lt; A.size(); ++i)
    for (auto j = 0; j &lt; A[0].size(); ++j) 
      if (i * j == 0 || i == A.size() - 1 || j == A[i].size() - 1) dfs(A, i, j);
  return accumulate(begin(A), end(A), 0, [](int s, vector&lt;int&gt; &amp;r)
    { return s + accumulate(begin(r), end(r), 0); });
}
};