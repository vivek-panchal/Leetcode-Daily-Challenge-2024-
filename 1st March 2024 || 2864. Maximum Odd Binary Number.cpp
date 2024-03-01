class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.length();
        int cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') cnt1++;
            else cnt0++;
        }

        string res = "";
        while(cnt1 > 1){
            res+='1';
            cnt1--;
        }

        while(cnt0 > 0){
            res+='0';
            cnt0--;
        }

        if(cnt1){
            res+='1';
        }

        return res;
        
    }
};
