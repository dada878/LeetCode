class Solution {
public:
    vector&lt;int&gt; finalPrices(vector&lt;int&gt;&amp; prices) {
        stack&lt;int&gt; s;
        vector&lt;int&gt; result(prices.size());
        prices.push_back(0);
        for (int i = 0; i &lt; prices.size(); i++) {
            while (!s.empty() &amp;&amp; prices[s.top()] &gt;= prices[i]) {
                result[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};