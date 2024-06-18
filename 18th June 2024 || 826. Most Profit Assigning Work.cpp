class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int maxProfit=0;
        int totalProfit=0;
        for(int i=0;i<worker.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int j=0;
        for(int work:worker){
            while(work>=v[j].first && j<worker.size()){
                maxProfit=max(maxProfit,v[j].second);
                j++;
            }
            totalProfit+=maxProfit;
        }
        return totalProfit;
    }
};
