class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        int count=0;

        for(auto it : s){
            mp[it]++;
        }

        for(auto it: t){
            if(mp[it]){
                mp[it]--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};
