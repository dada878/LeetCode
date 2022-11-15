//https://leetcode.com/problems/count-complete-tree-nodes
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void dfs(TreeNode* node, int &counter) {
        if (node == NULL) return;
        else counter++;
        dfs(node->left, counter);
        dfs(node->right, counter);
    }
    int countNodes(TreeNode* root) {
        int counter = 0;
        dfs(root, counter);
        return counter;
    }
};