class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prev=0;
        int cnt=0;
        int ans=0;

        for(auto str: bank){
            cnt=0;
            for( char ch:str){
                if(ch=='1'){
                    cnt++;
                }
            }
            if(cnt!=0){
                ans+=(cnt*prev);
                prev=cnt;
            }
        }
        return ans;
    }
};
