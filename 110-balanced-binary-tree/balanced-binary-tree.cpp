class Solution {
public:
    int check(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = check(root->left);
        if(lh == -1) return -1;

        int rh = check(root->right);
        if(rh == -1) return -1;

        int diff;
        if(lh > rh) diff = lh - rh;
        else diff = rh - lh;

        if(diff > 1) return -1;

        if(lh > rh) return lh + 1;
        return rh + 1;
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};