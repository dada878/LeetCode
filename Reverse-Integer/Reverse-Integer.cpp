class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = result*10 + x%10;
            x /= 10;
        }
        return result &gt; INT_MAX || result &lt; INT_MIN ? 0 : result;
    }
};