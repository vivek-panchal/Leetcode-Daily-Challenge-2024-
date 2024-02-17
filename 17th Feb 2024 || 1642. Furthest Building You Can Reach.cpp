class Solution {
public:
    int furthestBuilding(vector<int>&h,int b,int l){
        priority_queue<int,vector<int>,greater<int>>ld;
        int br=0;
        for(int i=0;i<h.size()-1;i++){
            if(h[i]<h[i+1]){
                if(ld.size()!=l)ld.push(h[i+1]-h[i]);
                else{
                    int k=h[i+1]-h[i];
                    if(!ld.empty() && ld.top()<k){
                        br+=ld.top();
                        ld.pop();
                        ld.push(k);
                    }else{
                        br+=k;
                    }
                    if(br>b)return i;
                }
            }
        }
        return h.size()-1;
    }
};
