class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();
        int high = 0, low = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                low++;
                high++;
            }
            
            if(s[i] == ')'){
                low = max(0, low - 1);
                high--;
            }
            
            if(s[i] == '*'){
                low = max(0, low - 1);
                high++;
            }
            
            if(high < 0)
                return false;
        }
        return (low == 0);
    }
};
