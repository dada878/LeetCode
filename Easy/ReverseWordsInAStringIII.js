"Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/"
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const strs = s.split(" ");
    let result = "";
    for (let str of strs) {
        result += str.split("").reverse().join("") + " ";
    }
    return result.trim();
};
