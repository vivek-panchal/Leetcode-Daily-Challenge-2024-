class Solution {
public:
    TreeNode* createMapping(TreeNode*&root,int target,map< TreeNode*,TreeNode* > &m){
        
        // mapping for node to its parent
        //as for every node ,its left chil ,right child and its parent will burn
        //we can access left and right. but for parent we need mapping
        TreeNode* res = NULL;
        queue<TreeNode*>q;
        q.push(root);
        m[root]=NULL;
        
        while(!q.empty()){
            TreeNode*front = q.front();
            q.pop();
            
            if(front->val==target)res = front;
            
            if(front->left){
                // as left child  parent will be front
                m[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                m[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
  
    // Burning Tree
    int burnTree(TreeNode*&root, map<TreeNode*,TreeNode*> &m){
        
        //creating a map to check if that node is already visited or not
        map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root]=true;
        
        //time to burn tree.
        int ans = 0;
        
        //Level Order Traversal
        while(!q.empty())
        {
            
            bool flag = 0;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
            TreeNode*front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
               }
            
            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
                }
            
            if(m[front] && !visited[m[front]]){
                flag=1;
                q.push(m[front]);
                visited[m[front]]=1;
                }
            }
            
            if(flag==1)
                ans++;
        }
        
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>nodeToParent ;
        TreeNode* startingNode= createMapping(root,start,nodeToParent);
        
        int ans = burnTree(startingNode,nodeToParent);
        return ans;
    }
};
