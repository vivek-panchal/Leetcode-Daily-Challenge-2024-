class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count = 0;
        for(int i=0;i<n;i++){
           string str = details[i];
           char char1 = str[11];
           char char2 = str[12];
           int value = (char1-'0')*10+(char2-'0');
            if(value>60){
                count++;
            }
        }
        return count;
    }
};
