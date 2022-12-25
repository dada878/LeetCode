class Solution {
public:
    vector&lt;int&gt; answerQueries(vector&lt;int&gt;&amp; v, vector&lt;int&gt;&amp; q) {
        sort(v.begin(),v.end());
        for(int i=1;i&lt;v.size();i++)v[i]+=v[i-1];
        vector&lt;int&gt; ans;
        for(int x:q){
            int idx=upper_bound(v.begin(),v.end(),x)-v.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};