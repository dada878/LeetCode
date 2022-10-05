"Link: https://leetcode.com/problems/plus-one/"


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        string = ""
        for i in digits:
            string += str(i)
        string = str(int(string)+1)
        result = []
        for i in string:
            result.append(i)
        return result
