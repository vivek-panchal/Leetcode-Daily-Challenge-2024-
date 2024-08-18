class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        int int2 = 0;
        int int3 = 0;
        int int5 = 0;
        
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        
        for (int i = 1; i < n; i++) {
            int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;
            
            if (nextUglyNumber == nextMultipleOf2) {
                int2++;
                nextMultipleOf2 = uglyNumbers[int2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                int3++;
                nextMultipleOf3 = uglyNumbers[int3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                int5++;
                nextMultipleOf5 = uglyNumbers[int5] * 5;
            }
        }
        
        return uglyNumbers[n - 1];
    }
};
