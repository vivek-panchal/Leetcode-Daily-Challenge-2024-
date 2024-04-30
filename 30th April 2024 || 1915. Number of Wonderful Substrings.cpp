class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        int n = word.length();
        vector<int> countPrefix(1 << 10, 0);

        int prefixXor = 0;
        countPrefix[0] = 1; 
        
        for (char c : word) {
            prefixXor ^= (1 << (c - 'a'));
            count += countPrefix[prefixXor];
            for (int i = 0; i < 10; ++i) {
                count += countPrefix[prefixXor ^ (1 << i)];
            }
            
            countPrefix[prefixXor]++;
        }
        return count;
    }
};
