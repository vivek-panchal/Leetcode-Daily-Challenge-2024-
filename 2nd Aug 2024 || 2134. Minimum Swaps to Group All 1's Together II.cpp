class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int countOnes=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                countOnes++;
            }
        }

        if(countOnes<=1){
            return 0;
        }

        int window=countOnes;
        int currOnes=0;
        for(int i=0;i<window;i++){
            if(nums[i]==1){
                currOnes++;
            }
        }
        int maxOnes=currOnes;

        for(int i=window;i<n+window;i++){
            int right =i%n;
            int left=(i-window)%n;

            if(nums[right]==1){
                currOnes++;
            }
            if(nums[left]==1){
                currOnes--;
            }
            maxOnes=max(maxOnes,currOnes);
        }

        return countOnes-maxOnes;
    }
};
