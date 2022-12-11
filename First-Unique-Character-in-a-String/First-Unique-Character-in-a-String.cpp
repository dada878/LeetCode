class Solution {
public:
    int firstUniqChar(string s) {
        map&lt;char, int&gt; counter;
        for (int i = 0; i &lt; s.length(); i++) {
            counter[s[i]]++;
        }
        for (int i = 0; i &lt; s.length(); i++) {
            if (counter[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};