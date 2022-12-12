class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        int a = 0, b = 1;
        for (int i = 0; i &lt; n; i++) {
            int tmp = b;
            b = a+b;
            a = tmp;
        }
        return b;
    }
};