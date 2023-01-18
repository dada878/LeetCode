// class Solution {
// public:
//     int maxSubarraySumCircular(vector&lt;int&gt;&amp; nums) {    
//         int maxSum = 0;
//         int curSum = 0;
//         int *startAddres;
//         int size = nums.size();
//         for (int i = 0; i &lt; nums.size() * 2; i++) {
//             if (startAddres == &amp;nums[i % size]) break;
//             if (curSum == 0) startAddres = &amp;nums[i % size];
//             curSum += nums[i % size];
//             maxSum = max(maxSum, curSum);
//             curSum = max(curSum, 0);
//         }
//         cout &lt;&lt; startAddres &lt;&lt; endl;
//         cout &lt;&lt; maxSum &lt;&lt; endl;
//         return 1;
//     }
// };
class Solution {
public:
    int maxSubarraySumCircular(vector&lt;int&gt;&amp; A) {
        int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            total_sum+=i; curr_sum1+=i; curr_sum2+=i;
            mxsum_subary=max(mxsum_subary,curr_sum1);
            if(curr_sum1&lt;0) curr_sum1=0;
           minsum_subary=min(curr_sum2,minsum_subary);
            if(curr_sum2&gt;0) curr_sum2=0;
        }
        return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
    }
};