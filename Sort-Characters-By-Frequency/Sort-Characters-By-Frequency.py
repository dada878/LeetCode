class Solution:
    def frequencySort(self, s: str) -&gt; str:
        count = Counter(s)
        tmp = []
        for i in count:
            tmp.append([i, count[i]])
        tmp.sort(key=lambda x: x[1] * -1)
        result = ""
        for i in tmp:
            result += i[0] * i[1]
        return result