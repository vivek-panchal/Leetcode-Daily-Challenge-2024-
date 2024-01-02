class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=0;
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
            n=max(n,mp[x]);
        }

        vector<vector<int>>ans(n);
        vector<set<int>> st(n);

        for(auto x:nums){
            for(int i=0;i<n;i++){
                if(st[i].find(x)==st[i].end()){
                    ans[i].push_back(x);
                    st[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};
