class Solution {
public:
    bool possibleBipartition(int N, vector&lt;vector&lt;int&gt;&gt;&amp; dislikes) {
        // typical Bipartition 
        if(dislikes.size()&lt;1)   return true;
        bool b=true;
        unordered_map&lt;int,unordered_set&lt;int&gt;&gt; um;
        unordered_map&lt;int,unordered_set&lt;int&gt;&gt;::iterator umi;
        vector&lt;int&gt; vt(N+1,0);
        // Record Edges 
        for( int i=1; i&lt;=N; i++){
            unordered_set&lt;int&gt; us;
            um.emplace( i, us);
        }
        for( int i=0; i&lt;dislikes.size(); i++){
            umi=um.find(dislikes[i][0]);
            if(umi-&gt;second.find(dislikes[i][1])==umi-&gt;second.end())  umi-&gt;second.emplace(dislikes[i][1]);
            umi=um.find(dislikes[i][1]);
            if(umi-&gt;second.find(dislikes[i][0])==umi-&gt;second.end())  umi-&gt;second.emplace(dislikes[i][0]);
        }
        // DFS
        for( int i=1; i&lt;=N; i++){
            if(vt[i]==0){// guranteed to visit all connected part 
                vt[i]=1;
                b=dfs( i, vt, um );
            }
            if(!b)  return false;
        }
        return b;
    }
    bool dfs( int i, vector&lt;int&gt;&amp; vt, unordered_map&lt;int,unordered_set&lt;int&gt;&gt;&amp; um ){
        bool b;
        unordered_map&lt;int,unordered_set&lt;int&gt;&gt;::iterator umi=um.find(i);
        for( unordered_set&lt;int&gt;::iterator usi=umi-&gt;second.begin(); usi!=umi-&gt;second.end(); usi++){
            if(vt[*usi]==0){
                vt[*usi]=vt[i]*-1;
                b=dfs( *usi, vt, um);
                if(!b)  return false;
            }else if(vt[*usi]==vt[i]){
                return false;
            }
        }
        return true;
    }
};