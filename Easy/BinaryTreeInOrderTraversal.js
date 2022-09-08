"Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/"

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
 * @return {number[]}
 */
 var inorderTraversal = function(root) {
    return traversal(root);
};

function traversal(tree, data=[]) {
    if (tree === null) return [];
    if (tree.left !== null) traversal(tree.left, data);
    data.push(tree.val);
    if (tree !== null) tree.val;
    if (tree.right !== null) traversal(tree.right, data);
    return data;
}