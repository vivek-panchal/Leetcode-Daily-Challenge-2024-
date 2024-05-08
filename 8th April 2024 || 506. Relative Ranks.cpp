class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> temp(score.begin(),score.end());
        sort(temp.begin(),temp.end(),greater<int>());
        int len = score.size();
        unordered_map<int,int> t;
        for(int i=0;i<len;i++){
            t[temp[i]]=i+1;
        }
        for(auto it:score){
            int pos = t[it];
            switch(pos){
                case 1:
                    ans.push_back("Gold Medal");
                    break;
                case 2:
                    ans.push_back("Silver Medal");
                    break;
                case 3:
                    ans.push_back("Bronze Medal");
                    break;
                default:
                    ans.push_back(to_string(pos));
                    break;
            }
        }
        return ans;
    }
};
