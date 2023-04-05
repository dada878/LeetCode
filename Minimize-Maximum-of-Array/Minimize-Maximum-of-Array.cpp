class Solution {
public:
    int minimizeArrayValue(vector&lt;int&gt;&amp; nums) {
        // init perfix sum
        vector&lt;long long&gt; psum(nums.size());
        psum[0] = nums[0];
        for (int i = 1; i &lt; nums.size(); i++) psum[i] = psum[i-1] + nums[i];
        int ans = nums[0];
        for (int i = 1; i &lt; nums.size(); i++) {
            // if (nums[i] &gt; ans) { // posible update answer
                // cout &lt;&lt; psum[i] - psum[0] &lt;&lt; endl;
                // if (ceil((double)(psum[i] - psum[0]) / (double)(i)) &gt; ans) {
                    ans = max(ans,(int)(ceil((double)(psum[i]) / (double)(i + 1))));
                    // cout &lt;&lt; ans &lt;&lt; endl;
                // }
            // }
        }
        return ans;
    }
};