class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> adj;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]]++;
            adj[roads[i][1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: adj){
            pq.push({it.second,it.first});
        }
        int count=n,val=0;
        while(!pq.empty()){
            val=pq.top().second;
            adj[val]=count;
            count--;
            pq.pop();
        }
        long long ans=0;
        for(int i=0;i<roads.size();i++){
            ans+=adj[roads[i][0]];
            ans+=adj[roads[i][1]];
        }
        return ans;
    }
};
