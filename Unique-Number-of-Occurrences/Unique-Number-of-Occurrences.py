class Solution:
    def uniqueOccurrences(self, arr: List[int]) -&gt; bool:
        unq = list(set(arr))
        counter = Counter(arr)
        tmp = []
        for i in unq:
            if counter[i] in tmp:
                return False
            tmp.append(counter[i])
        return True