class Solution {
public:
    int rob(vector&lt;int&gt;&amp; nums) {
        int rob1 = 0;
        int rob2 = 0;
        // [rob1, rob2, n, n+1]
        for (int i = 0; i &lt; nums.size(); i++) {
            int tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};