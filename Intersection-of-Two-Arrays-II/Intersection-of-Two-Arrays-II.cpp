class Solution {
public:
    vector&lt;int&gt; intersect(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {
        vector&lt;int&gt; result;
        map&lt;int, int&gt; counter;
        for (int i = 0; i &lt; nums1.size(); i++) {
            if (count(nums2.begin(), nums2.end(), nums1[i]) &gt; counter[nums1[i]]) {
                result.push_back(nums1[i]);
                counter[nums1[i]]++;
            }
        }
        return result;
    }
};