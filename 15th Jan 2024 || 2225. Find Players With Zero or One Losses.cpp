class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> winner;
        unordered_map<int,int> losser;

        for(int i=0;i<matches.size();i++){
            winner.insert(matches[i][0]);
            losser[matches[i][1]]++;
        }

        vector<int>win;
        vector<int>lose;

        for(auto w:winner){
            if(losser.find(w)==losser.end()){
                win.push_back(w);
            }
        }

        for(auto l: losser){
            if(l.second==1){
                lose.push_back(l.first);
            }
        }
        sort(win.begin(),win.end());
        sort(lose.begin(),lose.end());

        return {win,lose};
    }
};
