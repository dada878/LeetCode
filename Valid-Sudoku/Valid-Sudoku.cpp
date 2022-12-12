class Solution 
{
public:
    bool isValidSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) 
    {
        vector&lt;set&lt;char&gt;&gt; rows(9), cols(9), blck(9);                // memoize seen digits
        for (int i = 0; i &lt; 9; i++) 
            for (int j = 0; j &lt; 9; j++) 
                if (board[i][j] != '.')
                {
                    int d = board[i][j], b = (i/3)*3+j/3;
                    if (!rows[i].emplace(d).second) return false;   // [1] test rows
                    if (!cols[j].emplace(d).second) return false;   // [2] test columns
                    if (!blck[b].emplace(d).second) return false;   // [3] test blocks
                }
        return true;
    }
};