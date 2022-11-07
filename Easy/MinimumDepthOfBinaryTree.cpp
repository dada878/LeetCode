#include <vector>
#include <iostream>
#include <algorithm>
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
    vector<int> save;
    void bfs(TreeNode* node, int depth) {
        if (!node) return;
        if (!node->left && !node->right) {
            save.push_back(depth);
        } else {
            bfs(node->left, depth+1);
            bfs(node->right, depth+1);
        }
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        bfs(root, 1);
        return *min_element(save.begin(), save.end());
    }
};