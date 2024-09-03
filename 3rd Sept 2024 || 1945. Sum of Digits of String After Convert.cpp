class Solution {
public:
    int getLucky(string s, int k) {
        map<char,string>mpp;
        int i=1;
        string temp;
        for(char c='a';c<='z';c++){
            mpp[c]=to_string(i++);
        }
        for(auto it:s){
            temp+=mpp[it];
        }
        while(k>0){
            int sum=0;
            for(auto it:temp){
                sum+=it-'0';
            }
            temp.clear();
            temp=to_string(sum);
            --k;
        }
        int ans=0;
        ans=stoi(temp);
        return ans;
    }
};
