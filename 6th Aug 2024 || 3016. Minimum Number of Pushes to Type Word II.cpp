class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto it: word){
            freq[it-'a']++;
        }

        priority_queue<int>pq;
        for(auto it:freq){
            if(it!=0){
                pq.push(it);
            }
        }
        int k=0;
        int ind=0;
        int ans=0;
        while(!pq.empty()){
            if((k++)%8==0){
                ind++;
            }
            int f=pq.top();
            pq.pop();
            ans+=ind*f;
        }
        return ans;
    }
};
