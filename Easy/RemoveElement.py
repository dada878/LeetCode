"Link: https://leetcode.com/problems/remove-element/description/"


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        delCount = 0
        for i in range(len(nums)):
            if nums[i-delCount] == val:
                nums.pop(i-delCount)
                delCount += 1
        return len(nums)
