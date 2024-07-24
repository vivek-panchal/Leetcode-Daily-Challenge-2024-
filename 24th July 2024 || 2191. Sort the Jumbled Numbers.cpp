class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            int mp=0;
            if(temp==0){
                mp=mapping[0];
            }
            int x=1;
            while(temp>0){
                int dig=temp%10;
                mp+=x*mapping[dig];
                x=x*10;
                temp/=10;
            }
            pr.push_back({mp,i});
        }
        sort(pr.begin(),pr.end());
        vector<int>ans;
        for(auto it:pr){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};
