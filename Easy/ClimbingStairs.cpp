//Link: https://leetcode.com/problems/climbing-stairs
//Thanks: https://www.youtube.com/watch?v=Im8BTk1Pykw

class Solution {
    public:
        int climbStairs(int n) {
            if (n == 0) return 0;
            int a = 0, b = 1;
            for (int i = 0; i < n; i++) {
                int tmp = b;
                b = a+b;
                a = tmp;
            }
            return b;
        }
    };