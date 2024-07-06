class Solution {
public:
    int passThePillow(int n, int time) {
        int k=time/(n-1);
        if(k%2==0){
            int ans=time-k*(n-1);
            return ans+1;
        }
           int ans=time-k*(n-1);
           return n-ans;
    }
};
