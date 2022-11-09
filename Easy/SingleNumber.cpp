// https://leetcode.com/problems/single-number/description/
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> counter;
        vector<int> keys;
        for (int i = 0; i < nums.size(); i++) {
            counter[nums[i]]++;
            keys.push_back(nums[i]);
        }
        for (int i = 0; i < keys.size(); i++) {
            if (counter[keys[i]] == 1) return keys[i];
        }
        return 0;
    }
};