class Solution {
public:
    bool canPlaceFlowers(vector&lt;int&gt;&amp; flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) n--;
        } else {
    for (int i = 0; i &lt; flowerbed.size(); i++) {
                // cout &lt;&lt; i &lt;&lt; endl;
                // cout &lt;&lt; "===" &lt;&lt; 1 &lt;&lt; "===" &lt;&lt; endl;
                // cout &lt;&lt; "flowerbed[i] " &lt;&lt; flowerbed[i] &lt;&lt; endl;
                // cout &lt;&lt; "===" &lt;&lt; 2 &lt;&lt; "===" &lt;&lt; endl;
                // cout &lt;&lt; "flowerbed[i+1] " &lt;&lt; flowerbed[i+1] &lt;&lt; endl;
                // cout &lt;&lt; "===" &lt;&lt; 3 &lt;&lt; "===" &lt;&lt; endl;
                // cout &lt;&lt; (i == 0 &amp;&amp; flowerbed[i] == 0 &amp;&amp; flowerbed[i+1] == 0)&lt;&lt; endl;
                if (i == 0 &amp;&amp; flowerbed[i] == 0 &amp;&amp; flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i == flowerbed.size() - 1 &amp;&amp; flowerbed[i-1] == 0 &amp;&amp; flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i &gt; 0 &amp;&amp; i &lt; flowerbed.size() - 1 &amp;&amp; flowerbed[i-1] == 0 &amp;&amp; flowerbed[i] == 0 &amp;&amp; flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
                // cout &lt;&lt; "end a times" &lt;&lt; endl;
            }
        }
        return (n &lt;= 0);
    }
};