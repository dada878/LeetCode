"Link: https://leetcode.com/problems/search-insert-position/description/"


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target not in nums:
            nums.append(target)
            nums.sort()
        return nums.index(target)
