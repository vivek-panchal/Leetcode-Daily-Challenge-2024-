class Solution {
public:
    bool dfs(vector<vector<int>> &V, vector<bool> &vis, int source, int destination){

        if(source == destination)  return true;

        vis[source] = true;
        bool res = false;

        for(auto v : V[source]){
           if(!vis[v])   res |= dfs(V, vis, v, destination);
        }

        return res;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> V(n);
        vector<bool> vis(n, false);

        for(auto & edge : edges){
            V[edge[0]].push_back(edge[1]);
            V[edge[1]].push_back(edge[0]);
        }

        return(dfs(V, vis, source, destination));
    }
};
