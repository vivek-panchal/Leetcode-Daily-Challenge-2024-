class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int maxi=0;

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                st.pop();
            }
            if(st.size()>maxi){
                maxi=st.size();
            }
        }
        return maxi; 
    }
};
