class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for (auto ch: s){
            freq[ch]++;
        }

        string res;
        for (auto ch: order){
            while (freq[ch]--){
                res += ch;
            }

            freq.erase(ch);
        }

        for (auto it: freq){
            while (it.second--){
                res += it.first;
            }
        }

        return res;
    }
};
