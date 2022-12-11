class Solution {
public:
    int maxProfit(vector&lt;int&gt;&amp; prices) {
        int minVal = INT_MAX;
        int maxEarn = 0;
        for (int i = 0; i &lt; prices.size(); i++) {
            minVal = min(prices[i], minVal);
            maxEarn = max(prices[i] - minVal, maxEarn);
        }
        return maxEarn;
    }
};