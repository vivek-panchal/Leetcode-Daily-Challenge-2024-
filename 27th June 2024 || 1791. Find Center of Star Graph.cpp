class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u=edges[0][1];
        int v=edges[0][0];
        if(edges[1][0]==u || edges[1][1]==u){
            return u;
        }
        return v;
    }
};
