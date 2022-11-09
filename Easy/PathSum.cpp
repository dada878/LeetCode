#include <iostream>

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
    int target;
    bool result = false;
    void dfs(TreeNode* node, int sum) {
        if (node == NULL) return;
        sum += node->val;
        if (node->left == NULL && node->right == NULL && target == sum) {
            result = true;
        } else {
            dfs(node->left, sum);
            dfs(node->right, sum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0);
        return result;
    }
};