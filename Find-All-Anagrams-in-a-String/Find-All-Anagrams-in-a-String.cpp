class Solution {
public:
    vector&lt;int&gt; findAnagrams(string s, string p) {
        if (p.length() &gt; s.length()) return vector&lt;int&gt;(0);
        vector&lt;int&gt; ans;
        map&lt;char, int&gt; pcount, curcount;
        for (char pp : p) {
            pcount[pp]++;
        }
        for (int i = 0; i &lt; p.length(); i++) {
            curcount[s[i]]++;
        }
        for (int i = 0; i &lt;= s.length() - p.length(); i++) {
            // cout &lt;&lt; "=== " &lt;&lt; i &lt;&lt; "," &lt;&lt; s[i] &lt;&lt; " ===" &lt;&lt; endl;
            bool isSame = true;
            for (char chr = 'a'; chr &lt;= 'z'; chr++) {
                if (!(curcount[chr] == pcount[chr] &amp;&amp; pcount[chr] == 0))
                    // cout &lt;&lt; chr &lt;&lt; " : " &lt;&lt; curcount[chr] &lt;&lt; " " &lt;&lt; pcount[chr] &lt;&lt; endl;
                if (curcount[chr] != pcount[chr]) {
                    isSame = false;
                }
            }
            curcount[s[i]]--;
            curcount[s[i+p.length()]]++;
            // cout &lt;&lt; "curcount[" &lt;&lt; s[i] &lt;&lt; "]-- -&gt;" &lt;&lt; endl;
            // cout &lt;&lt; "curcount[" &lt;&lt; s[i+p.length()] &lt;&lt; "]++" &lt;&lt; endl;
            if (isSame) ans.push_back(i);
        }
        return ans;
    }
};