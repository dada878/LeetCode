class Solution {
public:
    map&lt;int, bool&gt; table {{1, false}, {2, true}, {3, false}};
    vector&lt;int&gt; getFactors(int n) {
        vector&lt;int&gt; result;
        for (int i = 1; i &lt; n; i++) {
            if (n % i == 0 &amp;&amp; count(result.begin(), result.end(), i) == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
    bool divisorGame(int n) {
        for (int i = 4; i &lt;= n; i++) {
            vector&lt;int&gt; factors = getFactors(i);
            bool result = true;
            for (int j = 0; j &lt; factors.size(); j++) {
                result = result &amp;&amp; table[i - factors[j]];
            }
            table[i] = !result;
        }
        return table[n];
    }
};