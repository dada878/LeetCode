"Link: https://leetcode.com/problems/climbing-stairs"
"Thanks: https://www.youtube.com/watch?v=Im8BTk1Pykw"
/**
 * @param {number} n
 * @return {number}
 */
 var climbStairs = function(n) {
    let data = [];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    for (let i = 1; i < n; i++) {
        const temp = data.slice();
        data[0] = temp[1];
        data[1] = temp[2];
        data[2] = temp[1] + temp[2];
    }
    return data[0];
};