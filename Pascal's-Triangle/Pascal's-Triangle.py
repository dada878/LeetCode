class Solution:
    def generate(self, numRows):
        """
        """
        if numRows == 0: return []
        start, end = 0, 0
        first_element = [1]
        current = first_element
        result = [first_element]
        while numRows &gt; 1:
            temp = []
            temp.append(start + current[0])
            for i in range(1,len(current)):
                temp.append(current[i-1] + current[i])
            temp.append(current[len(current)-1] + end)
            result.append(temp)
            current = temp
            numRows -= 1
        return result