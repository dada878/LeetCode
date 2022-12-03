class Solution {
public:
    bool containsDuplicate(vector&lt;int&gt;&amp; nums) {
        if (nums.size() == 0) return false;
        vector&lt;int&gt; seen;
        for (int i = 0; i &lt; nums.size(); i++) {
            if (count(seen.begin(), seen.end(), nums[i]) &gt; 0) return true;
            seen.push_back(nums[i]);
        }
        return false;
    }
};