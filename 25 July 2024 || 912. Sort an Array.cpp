class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end, vector<int>& temp){
        int left=start, right=mid+1;
        int s=end-start+1;
        for(int i=0; i<s; i++){       
            int i0=start+i;
            if(left>mid){
                temp[i0]=nums[right];
                right++;
            } else if (right>end){
                temp[i0]=nums[left];
                left++;
            } else  if (nums[left]<nums[right]){
                temp[i0]=nums[left];
                left++;
            } else{
                temp[i0]=nums[right];
                right++;
            }
        }
        for(int i=start; i<start+s; i++){
            nums[i]=temp[i];
        }
    }
    void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp ){
        if(end<=start) return;
        int mid=start+(end-start)/2;
        mergeSort(nums, start, mid, temp);
        mergeSort(nums, mid+1, end, temp);
        merge(nums, start, mid, end, temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1 ,temp);
        return nums;
    }
};
