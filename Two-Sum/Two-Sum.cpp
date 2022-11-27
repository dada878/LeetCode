class Solution {
public:
    vector&lt;int&gt; twoSum(vector&lt;int&gt;&amp; nums, int target) {
        vector&lt;int&gt; result;
        for (int i = 0; i &lt; nums.size(); i++) {
            for (int j = 0; j &lt; nums.size(); j++) {
                if (nums[i] + nums[j] == target &amp;&amp; i != j) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return nums;
    }
};