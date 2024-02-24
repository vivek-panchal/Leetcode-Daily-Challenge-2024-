class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,int firstPerson) {
        vector<pair<int, int>> adj[n];
        for (auto it : meetings) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        queue<pair<int, int>> pq; //[to,time]
        pq.push({0, 0});
        pq.push({firstPerson, 0});
        vector<int> TimeTaken(n, INT_MAX);
        TimeTaken[0] = 0, TimeTaken[firstPerson] = 0;
        vector<int> ans;
        while (!pq.empty()) {
            int to = pq.front().first;
            int time = pq.front().second;
            pq.pop();

            for (auto it : adj[to]) {
                int adjNode = it.first;
                int instantTime = it.second;
                if (adjNode == to) {
                    continue;
                } else if (instantTime >= time &&
                           TimeTaken[adjNode] > instantTime) {
                    TimeTaken[adjNode] = instantTime;
                    pq.push({adjNode, instantTime});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (TimeTaken[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
