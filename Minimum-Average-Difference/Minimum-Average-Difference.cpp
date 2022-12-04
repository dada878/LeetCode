class Solution {
public:
    int minimumAverageDifference(vector&lt;int&gt;&amp; nums) {
        long long totalSum = 0;
        for (int i = 0; i &lt; nums.size(); i++) {
            totalSum += nums[i];
        }
        long long prefixSum = 0;
        int minAveDiff = INT_MAX;
        int minAveDiffIndex;
        int prefixAve, suffixAve, aveDiff;
        for (int i = 0; i &lt; nums.size(); i++) {
            prefixSum += nums[i];
            totalSum -= nums[i];
            prefixAve = prefixSum / (i + 1);
            if (nums.size() == i+1) {
                suffixAve = 0;
            } else {
                suffixAve = totalSum / (nums.size() - (i + 1));
            }
            aveDiff = abs(prefixAve - suffixAve);
            if (aveDiff &lt; minAveDiff) {
                minAveDiffIndex = i;
                minAveDiff = aveDiff;
            };
        }
        return minAveDiffIndex;
    }
};