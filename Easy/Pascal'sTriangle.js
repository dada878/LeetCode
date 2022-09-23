"Link: https://leetcode.com/problems/pascals-triangle"
/**
 * @param {number} numRows
 * @return {number[][]}
 */
 var generate = function(numRows) {
    let result = [];
    for (let i = 0; i < numRows; i++) { //每一行
        let row = [];
        if (i == 0) {
            row = [1];
        } else if (i == 1) {
            row = [1, 1];
        } else if (i >= 2) {
            const lastRow = result[result.length-1];
            for (let j = 0; j < lastRow.length+1; j++) { //每行中的每個項目
                if (j > 0 && j < lastRow.length) {
                    row.push(lastRow[j-1] + lastRow[j]);
                } else {
                    row.push(1);
                }
            }
        }
        result.push(row);
    }
    return result;
};