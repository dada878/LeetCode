class Solution {
public:
    vector&lt;int&gt; successfulPairs(vector&lt;int&gt;&amp; s, vector&lt;int&gt;&amp; p, long long suc) {
        vector&lt;int&gt; v(s.size(),0);
        sort(p.begin(),p.end());
        for(int i=0;i&lt;s.size();i++)
        {
            int h=p.size()-1;
            int l=0;
            int mid;
            while(l&lt;=h)
            {
                mid = l + (h-l)/2;
                if((long long int)s[i]*(long long int)p[mid] &gt;= suc)
                    h = mid-1;
                else
                    l = mid+1;
            }
            v[i] = p.size()-1-h;
        }
        return v;
    }
};