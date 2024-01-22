class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums) mp[it]++;
        int a = -1, b = -1;

        for(int i = 1; i <= nums.size(); i++) {
            if(mp[i] == 2) a = i;
            if(mp[i] == 0) b = i;
        }

        return {a, b};
    }
};
