class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map&lt;char, int&gt; counter;
        for (int i = 0; i &lt; magazine.size(); i++) {
            counter[magazine[i]]++;
        }
        for (int i = 0; i &lt; ransomNote.size(); i++) {
            if (count(ransomNote.begin(), ransomNote.end(), ransomNote[i]) &gt; counter[ransomNote[i]]) {
                return false;
            }
        }
        return true;
    }
};