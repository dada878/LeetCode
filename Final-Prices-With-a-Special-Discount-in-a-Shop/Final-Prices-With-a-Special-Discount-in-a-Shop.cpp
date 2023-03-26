class Solution {
public:
    vector&lt;int&gt; finalPrices(vector&lt;int&gt;&amp; prices) {
        stack&lt;int&gt; s;
        vector&lt;int&gt; result(prices.size(), -1);
        for (int i = 0; i &lt; prices.size(); i++) {
            // cout &lt;&lt; "===== " &lt;&lt; prices[i] &lt;&lt;  " =====" &lt;&lt; endl;
            while (!s.empty() &amp;&amp; prices[s.top()] &gt;= prices[i]) {
                // cout &lt;&lt; "pop : " &lt;&lt; prices[s.top()] &lt;&lt; endl;
                // cout &lt;&lt; "val : " &lt;&lt; prices[s.top()] - prices[i] &lt;&lt; endl;
                result[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i &lt; prices.size(); i++) {
            if (result[i] != -1) continue;
            result[i] = prices[i];
        }
        return result;
    }
};