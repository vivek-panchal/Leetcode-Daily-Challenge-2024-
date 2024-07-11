class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char> st1;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                vector<int> temp;
                while(st1.top()!='('){
                    temp.push_back(st1.top());
                    st1.pop();
                }
                st1.pop();
                for(int j=0;j<temp.size();j++){
                    st1.push(temp[j]);
                }
            }else{
                st1.push(s[i]);
            }
        }
        string ans="";
        while(!st1.empty()){
            ans=st1.top()+ans;
            st1.pop();
        }
        return ans;
    }
};
