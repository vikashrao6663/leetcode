class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) return ans;

        ans.push_back(root->val);

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        for(int i = 0; i < left.size(); i++) {
            ans.push_back(left[i]);
        }

        for(int i = 0; i < right.size(); i++) {
            ans.push_back(right[i]);
        }

        return ans;
    }
};