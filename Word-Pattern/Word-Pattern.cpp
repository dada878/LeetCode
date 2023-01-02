class Solution {
public:
    vector&lt;string&gt; split(string src) {
        vector&lt;string&gt; result;
        result.push_back("");
        for (int i = 0; i &lt; src.length(); i++) {
            if (src[i] == ' ') {
                result.push_back("");
            } else {
                result[result.size() - 1] += src[i];
            }
        }
        return result;
    }
    bool wordPattern(string pattern, string s) {
        vector&lt;string&gt; splited = split(s);
        map&lt;char, string&gt; words;
        vector&lt;string&gt; used;
        if (pattern.length() != splited.size()) return false;
        for (int i = 0; i &lt; pattern.length(); i++) {
            if (words.count(pattern[i]) == 1 &amp;&amp; words[pattern[i]] != splited[i]) return false;
            else if (words.count(pattern[i]) == 0) {
                if (count(used.begin(), used.end(), splited[i]) &gt; 0) return false;
                used.push_back(splited[i]);
                words[pattern[i]] = splited[i];
            }
        }
        return true;
    }
};