class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                while(i+1<j&&s[i]==s[i+1]){
                    i++;
                }
                while(j-1>i&&s[j-1]==s[j]){
                    j--;
                }
                i++;
                j--;
            }else{
                return j-i+1;
            }
        }
        return j-i+1;
    }
};
