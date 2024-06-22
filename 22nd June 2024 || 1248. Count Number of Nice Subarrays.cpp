class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Convert even elements to 0 and odd elements to 1 in the 'nums' array.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }

        int cnt = 0; // Initialize the count of subarrays with exactly 'k' odd numbers.
        unordered_map<int, list<int>> mpp; // Create a map to store the prefix sum and its occurrences.
        int sum = 0; // Initialize the prefix sum.

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Calculate the prefix sum.

            if (sum == k) {
                cnt++; // If the prefix sum equals 'k', we found one subarray with exactly 'k' odd numbers.
            }

            int rem = sum - k; // Calculate the difference between the current prefix sum and 'k'.

            // If the difference exists in the map, 
            //it means there are subarrays with exactly 'k' odd numbers ending at the current index.
            if (mpp.find(rem) != mpp.end()) {
                cnt += mpp[rem].size(); // Increment the count by the number of such subarrays.
            }

            mpp[sum].push_back(i); // Store the current prefix sum's index in the map.
        }

        return cnt; // Return the count of subarrays with exactly 'k' odd numbers.
    }
};
