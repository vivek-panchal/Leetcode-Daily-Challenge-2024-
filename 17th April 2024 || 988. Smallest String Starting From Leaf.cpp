class Solution {
public:
    char indexToLetter(int index) {
    return 'a' + index;
}
   string lexmin(string str1,string str2)
    { return (str1<str2)?str1:str2;
    }
    void  find(TreeNode*root,string s,string &prev)
     {
            if(root->left==nullptr&&root->right==nullptr)
              {
                  reverse(s.begin(),s.end());
                  if(prev.size()==0)
                    {
                        prev=s;
                    }
                    else
                    prev=lexmin(s,prev);
                    s.pop_back();
                    return ;
              }
              if(root->left!=nullptr)
              find(root->left,s+indexToLetter(root->left->val),prev);
              if(root->right!=nullptr)
                find(root->right,s+indexToLetter(root->right->val),prev);
     }
    string smallestFromLeaf(TreeNode* root) {
        string s;
       s=s+indexToLetter(root->val);
        string prev="";
        find(root,s,prev);
       return prev;
        
    }
};
