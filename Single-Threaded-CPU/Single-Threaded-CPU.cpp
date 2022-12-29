class Solution {
public:
    vector&lt;int&gt; getOrder(vector&lt;vector&lt;int&gt;&gt;&amp; tasks) {
        using pp = pair&lt;int,pair&lt;int,int&gt;&gt;;
        vector&lt;pp&gt; vtr;
        int n = tasks.size();
        for(int i = 0; i &lt; n; ++i){
            vtr.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        sort(vtr.begin(),vtr.end());
        priority_queue&lt;pp, vector&lt;pp&gt;, greater&lt;pp&gt;&gt; pq;
        vector&lt;int&gt; res;
        int i = 0;
        long long curr_time = vtr[i].first;
        while(i &lt; n|| !pq.empty()){
            while(i &lt; n &amp;&amp; curr_time &gt;= vtr[i].first){
                pq.push({vtr[i].second.first,{vtr[i].second.second,vtr[i].first}});
                ++i;
            }
            curr_time = curr_time += pq.top().first;
            res.push_back(pq.top().second.first);
            pq.pop();
            if( i &lt; n &amp;&amp; curr_time &lt; vtr[i].first &amp;&amp; pq.empty())
                    curr_time = vtr[i].first;
        }
        return res;
    }
};