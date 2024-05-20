class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       return solve(nums,0,0);
    }
    int solve(vector<int>& nums,int index,int currentxor){
        if(index==nums.size()) return currentxor;
        
        int withxor=solve(nums,index+1,currentxor ^ nums[index]);
        int withoutxor=solve(nums,index+1,currentxor);
        return withxor+withoutxor;
    }
};
