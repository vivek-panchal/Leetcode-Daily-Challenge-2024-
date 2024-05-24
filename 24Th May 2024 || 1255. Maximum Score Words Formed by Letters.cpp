class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCount(26, 0);
        for (char letter : letters) {
            letterCount[letter - 'a']++;
        }
        
        return backtrack(words, score, letterCount, 0);
    }

private:
    int backtrack(const vector<string>& words, const vector<int>& score, vector<int>& letterCount, int index) {
        if (index == words.size()) {
            return 0;
        }

        int maxScore = backtrack(words, score, letterCount, index + 1);

        bool canForm = true;
        int wordScore = 0;
        vector<int> tempCount = letterCount;
        
        for (char c : words[index]) {
            if (--tempCount[c - 'a'] < 0) {
                canForm = false;
            }
            wordScore += score[c - 'a'];
        }

        if (canForm) {
            maxScore = max(maxScore, wordScore + backtrack(words, score, tempCount, index + 1));
        }

        return maxScore;
    }
};
