"Link: https://leetcode.com/problems/running-sum-of-1d-array"

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        result = []
        sum = 0
        for i in nums:
            sum += i
            result.append(sum)
        return result