"Link: https://leetcode.com/problems/two-sum/"
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
    for (let i in nums) {
        for (let j in nums) {
            if (nums[i] + nums[j] == target && i != j) {
                return [i,j];
            }
        }
    }
};