class Solution:
    def removeElement(self, nums: List[int], val: int) -&gt; int:
        delcount = 0
        for i in range(len(nums)):
            if nums[i-delcount] == val:
                nums.pop(i-delcount)
                delcount += 1
        return len(nums)