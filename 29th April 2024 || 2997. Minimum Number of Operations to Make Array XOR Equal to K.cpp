class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int temp:nums){
            sum^=temp;
        }
        int ans=0;
        k^=sum;
        while(k>0){
            ans+=k&1;
            k>>=1;
        }
        return ans;
    }
};
