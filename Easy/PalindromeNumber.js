"Link: https://leetcode.com/problems/palindrome-number/"
/**
 * @param {number} x
 * @return {boolean}
 */
 var isPalindrome = function(x) {
    let str = x.toString();
    let needLength = Math.trunc(str.length / 2);
    
    for (let i = 0; i < needLength; i++) {
        let len = str.length;
        if (str[i] != str[len - 1 - i]) {
            return false;  
        };
    };
    
    return true;
};