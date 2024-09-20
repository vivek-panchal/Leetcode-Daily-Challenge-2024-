class Solution {
public:
    string shortestPalindrome(string s) {
       int n=s.size();
       int j=0;
       for(int i=0;i<n;i++){
        if(s[j]==s[n-i-1]){
            j++;
        }
       }
       if(j==n) return s;
       string rem = s.substr(j); 
       reverse(rem.begin(), rem.end());
       return rem + shortestPalindrome(s.substr(0,j)) + s.substr(j);
    }
};
