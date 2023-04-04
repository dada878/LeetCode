class Solution {
public:
    int partitionString(string s) {
        vector&lt;bool&gt; mp(26);
        int ans = 1;
        for (auto c : s) {
            if (mp[c - 'a']) {
                ans++;
                for (int i = 0; i &lt; 26; i++) mp[i] = false;
            }
            mp[c - 'a'] = true;
        }
        return ans;
    }
};