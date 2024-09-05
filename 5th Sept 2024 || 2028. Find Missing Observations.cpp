class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (m + n) * mean;  
        
        int sumOfRolls = accumulate(rolls.begin(), rolls.end(), 0);
        
        int missingSum = totalSum - sumOfRolls;
        
        if (missingSum < n || missingSum > 6 * n) {
            return {};  
        }
        
        vector<int> result(n, missingSum / n);  
        
        int remainder = missingSum % n;  
        for (int i = 0; i < remainder; i++) {
            result[i]++;  
        }
        
        return result;
    }
};
