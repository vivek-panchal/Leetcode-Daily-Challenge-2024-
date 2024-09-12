class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> freq(26);
        for(int i=0 ; i<allowed.length() ; i++){
            freq[allowed[i]-'a']++;
        }
        int count = 0;
        for(auto word:words){
            bool flag = true;
            for(int i=0 ; i<word.size() ; i++){
                if(freq[word[i]-'a']==0){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
