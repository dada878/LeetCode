// https://leetcode.com/problems/house-robber-ii
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int rob1 = 0;
        int rob2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            int tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        int result1 = rob2;

        rob1 = 0;
        rob2 = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            int tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        int result2 = rob2;

        return max(result1, result2);
    }
};