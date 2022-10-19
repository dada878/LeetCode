"Link: https://leetcode.com/problems/find-pivot-index"

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        result = -1
        sum1 = 0
        sum2 = sum([x for x in nums[1:]])

        for i in range(len(nums)-1):
            if sum1 == sum2:
                result = i
                break
            sum1 += nums[i]
            sum2 -= nums[i+1]

        if result == -1 and sum1 == sum2:
            result = len(nums)-1

        return result
