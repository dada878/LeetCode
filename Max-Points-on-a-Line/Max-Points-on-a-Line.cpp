class Solution {
public:
    int maxPoints(vector&lt;vector&lt;int&gt;&gt;&amp; pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i&lt;n-1;i++){
            map&lt;double,int&gt; mp;
            for(int j=i+1;j&lt;n;j++){
                //calculating the slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if(pt[j][1]-pt[i][1]&lt;0 &amp;&amp;(pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
               //storing the slop into map
                    mp[x]++;
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};