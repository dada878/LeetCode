class Solution {
public:
    int totalFruit(vector&lt;int&gt;&amp; fruits) {
        unordered_map&lt;int, int&gt; mpp;
        int i = 0, j = 0, res = 0;
        while(j &lt; fruits.size())
        {
            mpp[fruits[j]]++;
            if(mpp.size() &lt;= 2) res = max(res, j-i+1);
            else
            {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res; 
    }
};
