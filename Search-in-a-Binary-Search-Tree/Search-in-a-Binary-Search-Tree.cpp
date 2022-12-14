/**
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        else if (root-&gt;val == val) return root;
        else if (val &gt; root-&gt;val) {
            return searchBST(root-&gt;right, val);
        } else {
            return searchBST(root-&gt;left, val);
        }
    }
};