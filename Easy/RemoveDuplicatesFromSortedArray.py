"Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/"


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        result = list(set(nums))
        for i in range(len(nums)):
            nums.pop(0)

        for i in result:
            nums.append(i)

        nums.sort()

        return len(result)
