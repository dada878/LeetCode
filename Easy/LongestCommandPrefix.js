"Link: https://leetcode.com/problems/longest-common-prefix/"
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let maxLength = 0;
    let result = "";
    strs.forEach(item => {maxLength = Math.max(item.length, maxLength)});
    for (let i = 0; i < maxLength; i++) {
        let wordCounter = new Map();
        for (let str of strs) {
            if (wordCounter[str[i]] === undefined) {
                 wordCounter[str[i]] = 1;
            } else {
                wordCounter[str[i]] ++;
            }
        }
        for (let i in wordCounter) {
            if (wordCounter[i] == strs.length) {
                result += i;
            } else {
                return result;
            }
        }
    }
    return result;
};