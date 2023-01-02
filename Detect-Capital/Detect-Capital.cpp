class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercount = 0;
        int lowercount = 0;
        for (int i = 0; i &lt; word.length(); i++) {
            if (isupper(word[i])) uppercount++;
            else lowercount++;
        }
        if (lowercount == 0 || uppercount == 0) return true;
        else if (uppercount == 1 &amp;&amp; isupper(word[0])) return true;
        return false;
    }
};