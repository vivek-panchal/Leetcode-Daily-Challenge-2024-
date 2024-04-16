class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth){
        
        if(root==NULL)
            return NULL;
        if(depth==2){
            TreeNode* leftNode= new TreeNode(val);
            TreeNode* rightNode= new TreeNode(val);
            
            leftNode->left=root->left;
            rightNode->right=root->right;
            
            root->left=leftNode;
            root->right=rightNode;
            
            return root;
            
        }
        
        root->left=solve(root->left,val,depth-1);
        root->right=solve(root->right,val,depth-1);
        return root;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode= new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        return solve(root,val,depth);
    }
};
