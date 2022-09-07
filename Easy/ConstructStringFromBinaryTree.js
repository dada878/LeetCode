"Link: https://leetcode.com/problems/construct-string-from-binary-tree/"
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
 var tree2str = function(root) {
    return main(root).toString();
};

function main(tree) {
    if (tree === null) return "";
    if (tree.left === null && tree.right === null) return tree.val;
    let data = `${tree.val}(${main(tree.left)})(${main(tree.right)})`;
    data = data.replace("())",")");
    if (data.endsWith("()")) data = data.substring(0, data.length-2);
    return data;
}