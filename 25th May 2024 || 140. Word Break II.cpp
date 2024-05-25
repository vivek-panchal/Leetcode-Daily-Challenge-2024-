class Solution {
public:
    void solve(int idx, string& s, int n, unordered_set<string>& wordSet, vector<string>& curr, vector<vector<string>>& result){
        if (idx == n) {
            result.push_back(curr);
            return;
        }
        string temp = "";
        for (int i = idx; i < n; i++) {
            temp += s[i];
            if (wordSet.find(temp) != wordSet.end()){
                curr.push_back(temp);
                solve(i + 1, s, n, wordSet, curr, result);
                curr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> result;
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> curr;
        solve(0, s, n, wordSet, curr, result);
        vector<string> ans;
        
        for (vector<string>& st : result) {
            string temp;
            for(string& str:st){
                temp+=str+' ';
            }
            temp.pop_back();//remove last space
            ans.push_back(temp);
        }
        return ans;
    }
};
