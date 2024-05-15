// get the thieves location
// perform a Daikhstra in reverse using max priority_queue
// from each node push the thieves location in all four directions and store with the maximum didtance and visit the node first by using th priority queue

class Solution {

int getMinDis(vector<pair<int,int>> thieves,int r,int c){
    int mini = 1e9;
    for(pair<int,int> thieve : thieves){
        mini = min(mini , (abs(thieve.first-r) + abs(thieve.second-c)));
    }
    return mini;
}

bool isValid(int r,int c,int n,int m){
    return (r>=0 && r<n && c>=0 && c<m);
}

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<pair<int,int>> thieves;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) thieves.push_back({i,j});
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        if(grid[0][0] ==1 || grid[n-1][m-1]==1) return 0; 

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,1e9));

        dis[0][0] = getMinDis(thieves,0,0);
        pq.push({getMinDis(thieves,0,0),{0,0}});
        while(!pq.empty()){
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            int safeFactor = pq.top().first;
            pq.pop();

            if(vis[r][c]==0){
                vis[r][c]=1;
                if(r==n-1 && c==m-1) return safeFactor;
                int dr[] = {-1,+1,0,0};
                int dc[] = {0,0,-1,+1};
                int sz =4;
                for(int i=0;i<sz;i++){
                    int rr = r+dr[i];
                    int cc = c+dc[i];
                    if(isValid(rr,cc,n,m) && vis[rr][cc]==0){
                        int w_temp= getMinDis(thieves,rr,cc);
                        if(dis[rr][cc] >  min(dis[r][c],w_temp) ){
                            dis[rr][cc] = min(dis[r][c],w_temp) ;
                            pq.push({dis[rr][cc],{rr,cc}});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];        
    }

};
