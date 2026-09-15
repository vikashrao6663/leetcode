class Solution {
public:
    bool same(TreeNode*p,TreeNode*q){
        if(p==NULL && q==NULL)
        return true;
        if(p==NULL || q==NULL)
        return false;
        if(p->val!=q->val)
        return false;
        return same(p->left,q->left) && 
               same(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(sub == NULL)
        return true;
        if(root == NULL)
        return false;
        if(same(root,sub))
        return true;
        return isSubtree(root->left,sub) ||
               isSubtree(root->right,sub);
    }
};