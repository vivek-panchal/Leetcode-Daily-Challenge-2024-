class Solution {
public:
    int scoreOfString(string s) {
        long long sum=0;
        for(int i=0;i<s.length()-1;i++){
            char a1=s[i];
            char a2=s[i+1];
            int b1=static_cast<int>(a1);
            int b2=static_cast<int>(a2);
            sum+=abs(b1-b2);
        }
        return sum;
    }
};
