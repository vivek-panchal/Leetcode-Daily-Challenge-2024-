class Solution {
public:
    void solve(TreeNode* root, vector<int>&mp, int &ans){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);

        if(root->left ==NULL && root->right ==NULL){
            int temp=0;
            for(int i=1;i<=9;i++){
                if(mp[i]%2!=0){
                    temp++;
                }
            }
            if(temp<=1){
                ans++;
            }
        }
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int> mp(10,0);
        solve(root,mp,ans);
        return ans;
    }
};
