// https://leetcode.com/problems/ugly-number/
class Solution {
public:
    void checkNum(int &n, int m) {
        if (n <= 0) return;
        while (n % m == 0) n /= m;
    }
    bool isUgly(int n) {
        if (n <= 0) return false;
        checkNum(n, 2);
        checkNum(n, 3);
        checkNum(n, 5);
        return n > 1 ? false : true;
    }
};