class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        else if(root->val==2){ 
            if(evaluateTree(root->left)==1 || evaluateTree(root->right)==1){
                return 1;
            }else{
                return 0;
            }
        }
        else{ 
            if(evaluateTree(root->left)==1 && evaluateTree(root->right)==1){
                return 1;
            }else{
                return 0;
            }
        }
    }
};
