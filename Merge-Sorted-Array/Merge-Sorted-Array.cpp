class Solution {
public:
    void merge(vector&lt;int&gt;&amp; nums1, int m, vector&lt;int&gt;&amp; nums2, int n) {
        int last = m + n -1;
        while (m &gt; 0 &amp;&amp; n &gt; 0) {
            if (nums1[m-1] &gt; nums2[n-1]) {
                nums1[last] = nums1[m-1];
                m--;
            } else {
                nums1[last] = nums2[n-1];
                n--;
            }
            last--;
        }
        while (n &gt; 0) {
            nums1[last] = nums2[n - 1];
            n--;
            last--;
        }
    }
};