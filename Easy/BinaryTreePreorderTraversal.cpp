// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
#include <iostream>
#include <vector>
using namespace std;

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
    void dfs(TreeNode* node, vector<int> &result) {
        if (node == NULL) return;
        result.push_back(node->val);
        dfs(node->left, result);
        dfs(node->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};