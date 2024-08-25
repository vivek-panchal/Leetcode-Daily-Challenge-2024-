class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
       if(root==NULL){
           return ans;
       }

       stack<TreeNode*> st;
       st.push(root);
       while(!st.empty()){
           TreeNode* top=st.top();
           st.pop();
           ans.push_back(top->val);
           if(top->left){
               st.push(top->left);
           }
           if(top->right){
               st.push(top->right);
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
