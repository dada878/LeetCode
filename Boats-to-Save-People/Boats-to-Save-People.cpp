class Solution {
public:
    int numRescueBoats(vector&lt;int&gt;&amp; people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int l = 0, r = people.size() - 1;
        while (l &lt;= r) {
            if (people[l] + people[r] &lt;= limit) l++;
            r--;
            ans++;
        }
        return ans;
    }
};