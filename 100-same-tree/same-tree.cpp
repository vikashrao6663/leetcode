class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(q==NULL && p==NULL) return true;
       if(q==NULL || p==NULL) return false;

       if(p->val!=q->val) return false;
        bool leftans=isSameTree(p->left,q->left);
        if(leftans==false) return false;

        bool rightans=isSameTree(p->right,q->right);
        if(rightans==false) return false;
         
         return true;
      
    }
};