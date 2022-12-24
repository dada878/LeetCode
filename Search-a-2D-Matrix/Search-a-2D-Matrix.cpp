class Solution {
public:
    bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int mid;
        int low = 0;
        int high = m * n - 1;
        while (low &lt; high) {
            mid = (low + high) / 2;
            int curVal = matrix[mid / n][mid % n];
            if (curVal == target) return true;
            else if (curVal &gt; target) high = mid;
            else low = mid + 1;
        }
        return matrix[low / n][low % n] == target ? true: false;
    }
};