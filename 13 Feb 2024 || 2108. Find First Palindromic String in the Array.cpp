class Solution {
public:
    bool checkpalindrome(string &s){
        string c=s;
        int n=s.size();
        for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
        if(s==c)return 1;
        return 0;
    }
    string firstPalindrome(vector<string>& words) {
        int l=words.size();
        string s;
        for(int i=0;i<l;i++){
            s=words[i];
            if(checkpalindrome(s)==1)return s;
        }
        return "";
    }
};
