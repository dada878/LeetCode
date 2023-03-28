// class Solution {
// public:
//     int mincostTickets(vector&lt;int&gt;&amp; days, vector&lt;int&gt;&amp; cost) {
//         vector&lt;int&gt; dp(365);
//         int base = 35;
//         for (int i = 1 + base; i &lt;= 365 + base; i++) {
//             if (count(days.begin(), days.end(), i - base)) {
//                 dp[i] = INT_MAX;
//                 dp[i] = min(dp[i], dp[i-1] + cost[0]);
//                 dp[i] = min(dp[i], dp[i-7] + cost[1]);
//                 dp[i] = min(dp[i], dp[i-30] + cost[2]);
//             } else {
//                 dp[i] = dp[i-1];
//             }
//         }
//         return days[days.size() - 1];
//     }
// };
class Solution {
public:
    int mincostTickets(vector&lt;int&gt;&amp; days, vector&lt;int&gt;&amp; cost) {
        vector&lt;int&gt; dp(400, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i &lt;= 365; i++) {
            if (count(days.begin(), days.end(), i)) {
                if (i &gt;= 1) dp[i] = min(dp[i], dp[i-1] + cost[0]);
                else dp[i] = min(dp[i], 0 + cost[0]);
                if (i &gt;= 7) dp[i] = min(dp[i], dp[i-7] + cost[1]);
                else dp[i] = min(dp[i], 0 + cost[1]);
                if (i &gt;= 30) dp[i] = min(dp[i], dp[i-30] + cost[2]);
                else dp[i] = min(dp[i], 0 + cost[2]);
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[days[days.size()-1]];
    }
};