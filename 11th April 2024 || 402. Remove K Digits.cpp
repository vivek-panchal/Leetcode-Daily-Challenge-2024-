class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k==n)return "0";
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
            while(!st.empty()&&k>0&&st.top()>num[i]){
                st.pop();k--;
            }
            st.push(num[i]);
            if(st.size()==1&&st.top()=='0')st.pop();
        }
        while(k&&!st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        if(ans=="")return "0";
        else reverse(ans.begin(),ans.end());
        return ans;
    }
};
