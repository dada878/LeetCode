class Solution {
public:
    int compress(vector&lt;char&gt;&amp; chars) {
        int n = chars.size();
        if (n == 1) {
            return 1;
        }
        int i = 0, j = 0;
        while (i &lt; n) {
            int count = 1;
            while (i &lt; n - 1 &amp;&amp; chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            chars[j++] = chars[i++];
            if (count &gt; 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};