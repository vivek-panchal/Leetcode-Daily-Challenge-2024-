class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;

        map<string,int>mp;
        string temp=s1+" "+s2;
        string ch="";
        for(int i=0;i<temp.size();i++){
            if(temp[i] == ' '){
                ans.push_back(ch);
                ch="";
            }else{
                ch+=temp[i];
            }

        }
        ans.push_back(ch);
        for(auto x:ans){
            mp[x]++;
        }

        vector<string>v;
        for(auto it:mp){
            if(it.second==1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};
