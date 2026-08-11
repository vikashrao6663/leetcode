class Solution {
public:
    long long maxtree(TreeNode* root) {
        if(root == NULL) return LLONG_MIN;

        return max((long long)root->val,max(maxtree(root->left), maxtree(root->right)));
    }

    long long mintree(TreeNode* root) {
        if(root == NULL) return LLONG_MAX;

        return min((long long)root->val,min(mintree(root->left), mintree(root->right)));
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        if((long long)root->val <= maxtree(root->left)) return false;
        if((long long)root->val >= mintree(root->right)) return false;
        return isValidBST(root->left) &&isValidBST(root->right);
    }
};