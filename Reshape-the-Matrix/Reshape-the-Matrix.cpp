class Solution {
public:
    vector&lt;vector&lt;int&gt;&gt; matrixReshape(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) return mat; // edge case
        vector&lt;vector&lt;int&gt;&gt; reshape(r,vector&lt;int&gt;(c));
        vector&lt;int&gt; res;
        for (int i = 0; i &lt; mat.size(); i++) {
            for (int j = 0; j &lt; mat[0].size(); j++) {
                res.push_back(mat[i][j]);
            }
        }
        int i = 0, j = 0, index = 0;
        while (i &lt; r) {
            j = 0;
            while (j &lt; c) {
                reshape[i][j] = res[index];
                j++;
                index++;
            }
            i++;
        }
        return reshape;
    }
};