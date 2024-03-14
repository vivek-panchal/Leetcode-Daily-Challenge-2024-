class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> freq; // To store the frequency of prefix sums

        for (int num : nums) {
            sum += num;
            if (sum == goal)
                count++;

            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.find(sum - goal) != freq.end())
                count += freq[sum - goal];

            freq[sum]++;
        }

        return count;
    }
};
