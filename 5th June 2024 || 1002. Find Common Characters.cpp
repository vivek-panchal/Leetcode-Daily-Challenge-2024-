class Solution {
public:
    void fillCount(string& word, int count[26]){
        for(char &ch: word){
            count[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int n = words.size();

        int count[26] = {0};

        fillCount(words[0], count);

        for(int i=1; i<n; i++){
            int temp[26] = {0};

            fillCount(words[i], temp);

            for(int j=0; j<26; j++){
                count[j] = min(count[j], temp[j]);
            }
        }

        for(int i=0; i<26; i++){
            int c=count[i];
            while(c--){
                //cahracter representing ith index
                result.push_back(string(1, i+'a'));
            }
        }

        return result;
    }
};
