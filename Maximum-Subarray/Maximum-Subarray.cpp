class Solution {
public:
    int maxSubArray(vector&lt;int&gt;&amp; nums) {
        int curSum = 0;
        int maxSum = nums[0];
        for (int i = 0; i &lt; nums.size(); i++) {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            curSum = max(curSum, 0);
        }
        return maxSum;
    }
};