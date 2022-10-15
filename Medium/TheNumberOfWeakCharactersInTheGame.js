"Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game"
"Thanks: https://www.cnblogs.com/cnoodle/p/15854176.html"
/**
 * @param {number[][]} properties
 * @return {number}
 */
 var numberOfWeakCharacters = function(properties) {
    properties = properties.sort((a, b) => a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
    let weakCharacters = 0;
    let max = 0;
    for (let i = 0; i < properties.length; i++) {
        if (properties[i][1] < max) {
            weakCharacters++;
        }
        max = Math.max(max, properties[i][1]);
    }
    return weakCharacters;
};