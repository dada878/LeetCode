// https://leetcode.com/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            curSum = max(curSum, 0);
        }
        return maxSum;
    }
};
