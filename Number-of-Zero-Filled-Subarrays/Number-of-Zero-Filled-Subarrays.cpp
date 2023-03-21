class Solution {
public:
    long long zeroFilledSubarray(vector&lt;int&gt;&amp; nums) {
        long long len = 0;
        long long ans = 0;
        nums.push_back(-1);
        for (int &amp;num : nums) {
            if (num == 0) {
                len++;
            } else {
                ans += (len * (len + 1)) / 2;
                len = 0;
            }
        }
        return ans;
    }
};