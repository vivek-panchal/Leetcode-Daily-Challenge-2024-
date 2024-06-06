class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        if(hand.size()%groupSize){
            return false;
        }
        for(auto it:hand){
            mp[it]++;
        }
        while(!mp.empty()){
            auto temp=mp.begin();
            int card=temp->first;
            int freq=temp->second;
            for(int i=0;i<groupSize;i++){
                if(mp[card+i]==0){
                    return false;
                }
                else{
                    mp[card+i]--;
                    if(mp[card+i]<1) mp.erase(card+i);
                }
            }
        }
        return true;
    }
};
