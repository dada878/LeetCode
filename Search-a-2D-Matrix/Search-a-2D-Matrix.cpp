class Solution {
public:
    bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {
        for (int i = 0; i &lt; matrix.size(); i++) {
            for (int j = 0; j &lt; matrix[0].size(); j++) {
                if (target == matrix[i][j]) return true;
            }
        }
        return false;
    }
};