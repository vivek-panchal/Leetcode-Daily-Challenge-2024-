class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root,int t=0) {
        
        if(root==NULL) return 0;

        int ans=0;
        if(root->left==NULL && root->right==NULL && t) ans=root->val;
        ans+=sumOfLeftLeaves(root->left,1)+sumOfLeftLeaves(root->right,0);
        return ans; 
    }
};
