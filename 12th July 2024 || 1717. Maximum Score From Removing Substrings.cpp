class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st,st2;
        int total = 0;
        int f=1;
        if(x>y)f=1;
        else f=0;
        for (char c : s) {
            char ch = c;
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if (x > y) { // remove all abs first
                if (ch == 'b' && st.top() == 'a') {
                    st.pop();
                    total += x;
                } else {
                    st.push(ch);
                }
            }
            else{
                if(ch=='a' && st.top()=='b'){
                    st.pop();
                    total+=y;
                }
                else{
                    st.push(ch);
                }
            }
        }
        while(!st.empty()) {
            char ch=st.top();
            st.pop();
            cout<<ch;
            if(st2.empty()){
                st2.push(ch);
            }
            else{
                if(!f){
                   if(ch=='a' && st2.top()=='b'){
                        st2.pop();
                        total+=x;//ab
                   }
                   else{
                        st2.push(ch);
                   }
                }
                else{
                    if(ch=='b' && st2.top()=='a') {
                        st2.pop();
                        total+=y;//ba
                    }
                    else{
                        st2.push(ch);
                    }
                }
            }
        }
     return total;
    }
};
