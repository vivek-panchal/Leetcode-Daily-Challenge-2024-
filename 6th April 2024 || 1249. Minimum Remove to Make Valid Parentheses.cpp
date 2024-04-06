class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;

        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]=='('){
                    st.push({'(',i});
                }
                else if(st.empty() && s[i]==')'){
                    s[i]='-';
                }
                else if(s[i]==')' && st.top().first=='('){
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            pair<char,int> temp=st.top();
            st.pop();
            s[temp.second]='-';
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='-'){
                ans+=s[i];
            }
        }

        return ans;

    }
};
