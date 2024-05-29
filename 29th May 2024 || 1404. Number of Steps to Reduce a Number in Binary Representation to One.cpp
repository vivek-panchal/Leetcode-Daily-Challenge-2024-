class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s!="1") {
            int len = s.length();
            if(s[len-1]=='1') {
                int count = 0;
                for(int i=len-1; i>=0; i--) {
                    if(s[i]=='1')
                        count += 1;
                    else
                        break;
                }
                if(count<len) {
                    s[len-count-1] = '1';
                    s = s.substr(0, len-count);
                }
                else if(count==len){
                    s = '1';
                }
                steps += count;
                steps += 1;
            }
            else {
                int count = 0;
                for(int i=len-1; i>=0; i--) {
                    if(s[i]=='0')
                        count += 1;
                    else
                        break;
                }
                steps += count;
                s = s.substr(0, len-count);
            }
        }
        return steps;
    }
};
