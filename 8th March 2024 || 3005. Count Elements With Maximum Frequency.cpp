class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0, ans = 0;
        int freq[101] = {0};
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > maxFreq) {
                maxFreq = freq[nums[i]];
                ans = maxFreq;
            } else if(freq[nums[i]] == maxFreq) {
                ans += freq[nums[i]];
            }
        }
        return ans;
    }
};
