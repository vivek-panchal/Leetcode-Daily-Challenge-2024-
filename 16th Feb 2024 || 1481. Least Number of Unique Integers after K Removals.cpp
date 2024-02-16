class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int result=v.size();
        for(auto it:v){
            if(it<=k){
                k-=it;
                result--;
            }
            else
            break;
        }
        return result;
    }
};
