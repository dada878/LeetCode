class Solution {
public:
    bool isHappy(int n) {
        vector&lt;int&gt; seen;
        while (n != 1) {
            int tmp = 0;
            while (n &gt; 0) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            if (count(seen.begin(), seen.end(), tmp) &gt; 0) {
                return false;
            }
            seen.push_back(tmp);
            n = tmp;
        }
        return true;
    }
};