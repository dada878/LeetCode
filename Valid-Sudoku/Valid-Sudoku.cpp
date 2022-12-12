class Solution 
{
public:
    bool isValidSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) 
    {
        // check row
        for (int i = 0; i &lt; 9; i++) {
            map&lt;char, int&gt; table;
            for (int j = 0; j &lt; 9; j++) {
                if (board[i][j] != '.' &amp;&amp; table[board[i][j]] &gt; 0) return false;
                table[board[i][j]]++;
            }
        }
        // check column
        for (int i = 0; i &lt; 9; i++) {
            map&lt;char, int&gt; table;
            for (int j = 0; j &lt; 9; j++) {
                if (board[j][i] != '.' &amp;&amp; table[board[j][i]] &gt; 0) return false;
                table[board[j][i]]++;
            }
        }
        // check grid area
        for (int i = 0; i &lt; 3; i++) {
            for (int j = 0; j &lt; 3; j++) {
                map&lt;char, int&gt; table;
                for (int k = i * 3; k &lt; (i+1) * 3; k++) {
                    for (int l = j * 3; l &lt; (j+1) * 3; l++) {
                        cout &lt;&lt; k &lt;&lt; l &lt;&lt; endl;
                        if (board[k][l] != '.' &amp;&amp; table[board[k][l]] &gt; 0) return false;
                        table[board[k][l]]++;
                    }
                }
            }
        }
        return true;
    }
};