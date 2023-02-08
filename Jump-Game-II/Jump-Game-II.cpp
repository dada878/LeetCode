// class Solution {
// public:
//     int solve(vector&lt;int&gt; nums, int start) {
//         int step = nums[start];
//         int maxStep = 0;
//         for (int i = start + 1; i &lt;= step + start; i++) {
//             for (int k = start + 1; k &lt; start + nums[i] - i + 1; k++) {
//                 maxStep = max(i + nums[k], maxStep);
//             }
//         }
//         return maxStep;
//     }
//     int jump(vector&lt;int&gt;&amp; nums) {
//         cout &lt;&lt; solve(nums, 0) &lt;&lt; endl;
//         cout &lt;&lt; solve(nums, nums[0]) &lt;&lt; endl;
//         return 1;
//     }
// };
class Solution {
public:
    int jump(vector&lt;int&gt;&amp; nums) {
      for(int i = 1; i &lt; nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }
      int ind = 0;
      int ans = 0;
      while(ind &lt; nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }
      return ans;
    }
};