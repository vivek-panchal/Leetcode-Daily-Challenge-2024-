class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        vector<int> ans;

        for(int i=1;i<=n;i++){
            v.push_back(to_string(i));
        }

        sort(v.begin(),v.end());

        for(auto it:v){
            ans.push_back(stoi(it));
        }
        return ans;
    }
};
