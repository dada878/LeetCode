"Link: https://leetcode.com/problems/binary-tree-pruning/"
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
 * @return {TreeNode}
 */
 var pruneTree = function(root) {
    prune(root);
    if (root.left == null && root.right == null && root.val == 0) return root.val = null;
    return root;
};

function prune(tree) {
    let childValues = [];
    if (tree.right !== null) {
        const data = prune(tree.right);
        if (!checkArray(data)) tree.right = null;
        childValues.push(data);
    }
    if (tree.left !== null) {
        const data = prune(tree.left);
        if (!checkArray(data)) tree.left = null;
        childValues.push(data);
    }
    childValues.push(tree.val);
    return childValues;
}

function checkArray(data) {
    if (typeof data == "object") {
        let check = false;
        for (let i of data) {
            if (typeof i == "object") {
                if (checkArray(i)) check = true;
            } else {
                if (i == 1) check = true;
            }
        }
        return check;
    } else {
        if (data == 1) return true;
        else return false;
    }
}