//Optimized code - O(n*m) and O(26*n) space
class Solution {
public:
    long long distinctNames(vector&lt;string&gt;&amp; ideas) {
        long long disName = 0;
        vector&lt;unordered_set&lt;string&gt;&gt; arr(26);
        for (string s : ideas) 
            arr[s[0] - 'a'].insert(s.substr(1));
        for (int i = 0; i &lt; 25; i++) {
            for (int j = i + 1; j &lt; 26; j++) {
                unordered_set&lt;string&gt; set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        return disName * 2;
    }
};