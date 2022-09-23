"Link: https://leetcode.com/problems/valid-parentheses/submissions/"
/**
 * @param {string} s
 * @return {boolean}
 */
 var isValid = function(s) {
    const start = ["(", "[", "{"];
    const endOf = {
        "}": "{",
        "]": "[",
        ")": "("
    };
    const stack = [];
    for (let i of s) {
        if (start.includes(i)) {
            stack.push(i);
        } else {
            const item = stack[stack.length-1];
            stack.pop();
            if (endOf[i] != item) {
                return false;
            }
        }
    }
    if (stack.length > 0) return false;
    return true;
};