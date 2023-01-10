class Solution {
public:
    int majorityElement(vector&lt;int&gt;&amp; nums) {
        map&lt;int, int&gt; counter;
        vector&lt;int&gt; seen;
        for (int i = 0 ;i &lt; nums.size(); i++) {
            counter[nums[i]] ++;
            seen.push_back(nums[i]);
        }
        int maxVal;
        int maxCount = INT_MIN;
        for (int i = 0; i &lt; seen.size(); i++) {
            if (counter[seen[i]] &gt; maxCount) {
                maxVal = seen[i];
                maxCount = counter[seen[i]];
            }
        }
        return maxVal;
    }
};