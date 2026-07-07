class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;

        if(root == nullptr)
            return 0;

        for(Node* child : root->children){
            ans = max(ans, maxDepth(child));
        }

        return ans + 1;
    }
};