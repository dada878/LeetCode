"Link: https://leetcode.com/problems/add-two-numbers/"
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
 var addTwoNumbers = function(l1, l2) {
    let sum = readNode(l1) + readNode(l2);
    let reversedSum = String(sum).split("").reverse().join("");
    
    let result = new ListNode();
    result.val = reversedSum[0];
    reversedSum = reversedSum.substring(1);
    
    for (i of reversedSum) {
        insertNode(result, i);
    }
    return result;
};

function insertNode(node, val) {
    let point = node;
    while (point.next !== null) {
        point = point.next;
    }
    point.next = new ListNode();
    point.next.val = val;
    return node;
}

function arrayToNumber(array) {
    let result = "";
    for (let i of array) {
        result += i;
    }
    return BigInt(result);
}

function readNode(node) {
    let result = [];
    while (node !== null) {
        result.push(node.val);
        node = node.next;
    }
    result = arrayToNumber(result.reverse());
    return result;
}