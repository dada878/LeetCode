class Solution {
public:
    int maximumBags(vector&lt;int&gt;&amp; c, vector&lt;int&gt;&amp; rocks, int b) {
        vector&lt;int&gt;v;
        for(int i=0;i&lt;rocks.size();i++)     v.push_back(c[i]-rocks[i]);
        sort(v.begin(),v.end());
        int i=0;
        while(b&gt;0 and i&lt;c.size()){
            b-=v[i];
            i++;
        }
        return b&lt;0 ? i-1 : i;
    }
};