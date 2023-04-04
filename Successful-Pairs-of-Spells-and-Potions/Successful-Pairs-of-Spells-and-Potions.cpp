class Solution {
public:
    vector&lt;int&gt; successfulPairs(vector&lt;int&gt;&amp; spells, vector&lt;int&gt;&amp; potions, long long success) {
        // Sort the potions array in increasing order.
        sort(potions.begin(), potions.end());
        vector&lt;int&gt; answer;
        int m = potions.size();
        int maxPotion = potions[m - 1];
        for (auto&amp; spell : spells) {
            // Minimum value of potion whose product with current spell  
            // will be at least success or more.
            long long minPotion = ceil((1.0 * success) / spell);
            // Check if we don't have any potion which can be used.
            if (minPotion &gt; maxPotion) {
                answer.push_back(0);
                continue;
            }
            // We can use the found potion, and all potion in its right 
            // (as the right potions are greater than the found potion).
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            answer.push_back(m - index);
        }
        return answer;
    }
};