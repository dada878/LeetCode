class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector&lt;vector&lt;int&gt;&gt; dp (text1.length(), vector&lt;int&gt;(text2.length()));
        for (int i = 0; i &lt; text1.length(); i++) {
            for (int j = 0; j &lt; text2.length(); j++) {
                if (text1[i] == text2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                } else {
                    if (i &gt; 0 &amp;&amp; j &gt; 0) {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    } else if (i &gt; 0) {
                        dp[i][j] = dp[i-1][j];
                    } else if (j &gt; 0) {
                        dp[i][j] = dp[i][j-1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        // for (int i = 0; i &lt; dp.size(); ++i)
        // {
        //     cout &lt;&lt; "[ ";
        //     for (int j = 0; j &lt; dp[0].size(); ++j)
        //     {
        //         cout &lt;&lt; dp[i][j] &lt;&lt; ' ';
        //     }
        //     cout &lt;&lt; "]" &lt;&lt; endl;
        // }
        return dp[text1.length()-1][text2.length()-1];
    }
};
// dp[0][0] = "a" &amp; "a" = 1
// dp[0][1] = "a" &amp; "ac" = 1
// dp[0][2] = "a" &amp; "ace" = 1
// dp[1][0] = "ab" &amp; "a" = 1
// dp[1][1] = "ab" &amp; "ac" = 1
// dp[1][2] = "ab" &amp; "ace" = 1
// dp[2][0] = "abc" &amp; "a" = 1
// dp[2][1] = "abc" &amp; "ac" = 2
// dp[2][2] = "abc" &amp; "ace" = 2
// dp[3][0] = "abcd" &amp; "a" = 1
// dp[3][1] = "abcd" &amp; "ac" = 2
// dp[3][2] = "abcd" &amp; "ace" = 2
// dp[4][0] = "abcde" &amp; "a" = 1
// dp[4][1] = "abcde" &amp; "ac" = 2
// dp[4][2] = "abcde" &amp; "ace" = 3