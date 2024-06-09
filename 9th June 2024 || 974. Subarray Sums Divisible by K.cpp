class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int pre_sum=0,ans=0; 
        unordered_map<int,int>m; //subarray sum%k and its frequency
        m[0]=1; //subarray sum with zero elements
        for(auto it: nums){
            pre_sum+=it;
            int rem=pre_sum%k;
            if(rem<0) rem+=k;
            if(m.find(rem)!=m.end()) ans+=m[rem];  //new point will have one subarray with each existing point having same remainder
            m[rem]++;
        }
        return ans;
    }
};
