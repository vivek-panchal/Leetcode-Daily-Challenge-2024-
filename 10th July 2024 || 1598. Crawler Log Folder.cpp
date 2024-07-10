class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(int i=0;i<logs.size();i++){
            if(logs[i] == "./"){
                continue;
            }
            else if(logs[i] == "../"){
                if(res > 0){
                    res--;
                }
            }
            else{
                res++;
            }
        }
        return res;
    }
};
