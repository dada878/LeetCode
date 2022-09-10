"Link: https://leetcode.com/problems/same-tree/"

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
 var isSameTree = function(p, q) {
    return main(p) == main(q);
};

function main(tree) {
    if (tree === null) return "";
    return `${tree.val}(${main(tree.left)})(${main(tree.right)})`;
}