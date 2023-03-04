class Solution {
public:
    long long countSubarrays(vector&lt;int&gt;&amp; nums, int minK, int maxK) {
        long long n=nums.size(),mni=-1,mxi=-1,li=-1,ans=0;
        for(int i=0;i&lt;n;++i){
            if(nums[i]&lt;minK || nums[i]&gt;maxK) li=i,mni=-1,mxi=-1;
            else{
                if(nums[i]==minK) mni=i;
                if(nums[i]==maxK) mxi=i;
                if(mni!=-1 &amp;&amp; mxi!=-1) ans+=min(mni,mxi)-li;
            }
        }
        return ans;
    }
};