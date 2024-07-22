class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> temp;

        for(int i=0;i<names.size();i++){
            temp.push_back({heights[i],names[i]});
        }

        sort(temp.rbegin(),temp.rend());
        vector<string> ans;

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};
