class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
        return n+1;
    }
};

/*******************************Approach*******************************************
It is evident that the answer lies between [1,n+1]. So bring all the elements to their respective position
i.e if the element is 3 bring it to 3rd position or 2nd index.
for example if the array is [3,1,-4,7] let's say it is nums.
iterate through the array and neglect the element if it is greater than n or leass than equal to 0.
otherwise bring it to its position by swapping using condition while(nums[i]!=nums[nums[i]-1]).

at index 0 3 != nums[3-1] hence swap and the array becomes [-4,1,3,7]
now at index 0 value is negative hence neglect and move forward.
at index 1 1!=nums[1-1] hence swap now the array becomes [1,-4,3,7]
now at index 1 value is negative hence neglect and move forward.
at index 2 3==nums[3-1] the condition is true and 3 is at right position hence neglect and move forward.
at index 3 value is 7 which is greater than n hence neglect
So the final array is [1,-4,3,7]
now iterate through this array and find the first index for which nums[i]!=i+1 or the element which is not at correct position.
this is the answer so in [1,-4,3,7] ans is 2.

so you have to swap if nums[i]!=nums[nums[i]-1] along with the condition 0<nums[i]<=n for all the index.*/
