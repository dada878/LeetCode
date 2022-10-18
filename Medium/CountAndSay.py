"Link: https://leetcode.com/problems/count-and-say"

class Solution:
    def numString(self, n):
        result = ""
        counter = 0
        temp = ""
        for i in range(len(n)):
            if temp != n[i] and temp != "":
                result += f"{counter}{n[i-1]}"
                counter = 0
            temp = n[i]
            counter += 1
        result += f"{counter}{n[-1]}"
        return result

    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        else:
            result = "1"
            for i in range(n-1):
                result = self.numString(result)
            return result
