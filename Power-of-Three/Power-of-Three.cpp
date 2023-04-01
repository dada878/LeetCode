class Solution {
public:
    bool isPowerOfThree(int n){
        return (n &gt; 0) &amp;&amp; (1162261467 % n == 0);
    }
};