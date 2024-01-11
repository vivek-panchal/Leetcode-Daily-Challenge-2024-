class Solution {
public:
    void maxDiff(TreeNode* root,int &ans,int maxi,int mini){
        if(root==NULL){
            return;
        }
        int diff1=abs(root->val-maxi);
        int diff2=abs(root->val-mini);
        ans=max(ans,max(diff1,diff2));
        
        if(root->left) maxDiff(root->left,ans,max(root->val,maxi),min(root->val,mini));
        
        if(root->right)maxDiff(root->right,ans,max(root->val,maxi),min(root->val,mini));
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int ans=INT_MIN;
        maxDiff(root,ans,root->val,root->val);
        return ans;
    }
};
