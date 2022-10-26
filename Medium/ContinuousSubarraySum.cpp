// Link: https://leetcode.com/problems/continuous-subarray-sum/
// Thanks: https://www.youtube.com/watch?v=OKcrLfR-8mE

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = end(nums) - begin(nums);
        int sum = 0;
        map<int, int> table;
        table[0] = -1;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            int r = sum % k;
            if (table.count(r) == 0) {
                table[r] = i;
            } else if (i - table[r] > 1) {
                return true;
            }
        }
        return false;
    }
};