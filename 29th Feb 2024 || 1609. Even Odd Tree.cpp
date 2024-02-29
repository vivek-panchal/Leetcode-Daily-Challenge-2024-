class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level =0;
        while(!q.empty()){
            int n = q.size();
            int maxnode = INT_MAX;
            int minnode = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int nodeval = node->val;
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                if(level %2 !=0){
                    if(nodeval%2==0){
                        if(nodeval<maxnode){
                            maxnode = nodeval;
                        }
                        else{
                            
                            return false;
                        }
                    }
                    else{
                        
                        return false;
                    }
                }
                else{
                    if(nodeval%2!=0){
                        if(nodeval>minnode){
                            minnode = nodeval;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
            level++;
        }
        return true;
    }
};
