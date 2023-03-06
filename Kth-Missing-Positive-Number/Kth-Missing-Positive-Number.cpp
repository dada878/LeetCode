class Solution {
public:
    int findKthPositive(vector&lt;int&gt;&amp; arr, int k) {
        int ptr = 0;
        int cur = 1;
        while (k &gt; 0 &amp;&amp; ptr &lt; arr.size()) {
            cout &lt;&lt; ptr &lt;&lt; endl;
            if (arr[ptr] != cur) k--;
            else ptr++;
            cur++;
        }
        return cur + k - 1;
    }
};