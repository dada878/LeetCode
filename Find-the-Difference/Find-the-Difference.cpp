class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map&lt;char, int&gt; mp, mp2;
        for (auto c : t) mp[c]++;
        for (auto c : s) mp2[c]++;
        for (char i = 'a'; i &lt;= 'z'; i++) {
            if (mp[i] != mp2[i]) return i;
        }
        return 'a';
    }
};