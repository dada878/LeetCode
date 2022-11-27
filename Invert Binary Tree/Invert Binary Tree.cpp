class Solution {

public:

    TreeNode* invertTree(TreeNode* root) {

        if(!root) return NULL;

        else{     

            swap(root-&gt;left,root-&gt;right);

            invertTree(root-&gt;left);

            invertTree(root-&gt;right);

        }

        return root;

    }

};
