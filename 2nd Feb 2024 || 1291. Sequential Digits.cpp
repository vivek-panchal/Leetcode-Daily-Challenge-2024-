class Solution {
public:
    void generateSequentialDigits(int low, int high, int current, vector<int>& result) {
        if (current >= low && current <= high) {
            result.push_back(current);
        }
        int lastDigit = current % 10;
        if (lastDigit < 9) {
            int nextDigit = lastDigit + 1;
            if (nextDigit <= 9) {
                generateSequentialDigits(low, high, current * 10 + nextDigit, result);
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int digit = 1; digit <= 9; ++digit) {
            generateSequentialDigits(low, high, digit, result);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
