class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int n=nums.size();
        int temp=-1;
        for(int i=0;i<n;i++){
            if(count==0){
               temp=nums[i];
           }
           if(nums[i]==temp){
               count++;
           }
           else{
               count--;
           }
        }
        return temp;
    }
};
