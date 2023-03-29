class Solution {
public:
    int maxSatisfaction(vector&lt;int&gt;&amp; v) {
        sort(v.begin(), v.end(), greater&lt;int&gt;());
        for (int i = 1; i &lt; v.size(); i++) {
            v[i] += v[i-1];
        }
        int ans = 0;
        for (int i = 1; i &lt; v.size(); i++) {
            v[i] += v[i-1];
            ans = max(ans, v[i]);
        }
        return ans;
    }
};