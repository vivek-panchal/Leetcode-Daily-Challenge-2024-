class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;

        vector<vector<int>> v={{0,1},{1,0},{0,-1},{-1,0}};
        map<vector<int>,int> mp;
        for(auto it:obstacles){
          mp[it]++;
        }
        int ans=0;
        int d=0;
        for(auto it:commands){
          if(it==-1){
            d=(d+1)%4;
            continue;
          }
          if(it==-2){
            d=(d-1+4)%4;
            continue;
          }
          for(int i=1;i<=it;i++){
           int newX=x+v[d][0];
            int newY=y+v[d][1];
            if(mp.count({newX,newY})){
              break;
            }
            else{
              x=newX;
              y=newY;
            }
          }
          ans=max(ans,x*x+y*y);
          
        }
        
        return ans;
        
    }
};
