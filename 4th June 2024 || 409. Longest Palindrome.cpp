class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> counts;
        for(char ct:s){
            counts[ct]++;
        }

        int result=0;
        bool odd_found=false;

        for(auto & c:counts){
            if(c.second%2==0){
                result +=c.second;
            }
            else{
                odd_found=true;
                result+=c.second-1;
            }
        }
        if(odd_found==true){
            return result+1;
        }

        return result;
    }
};
