"Link: https://leetcode.com/problems/two-sum/"
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let table = {};
    for (let i in nums) {
        table[nums[i]] = i;
    }
    for (let i in nums) {
        let check = table[target - nums[i]];
        if (check && check != i) return [i, check];
    }
};

