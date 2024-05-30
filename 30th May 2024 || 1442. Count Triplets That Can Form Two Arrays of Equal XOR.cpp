class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int n = arr.size(), ans = 0, Xor = 0;
        unordered_map<int, pair<int, int>> mp;

        for(int i = 0 ; i < n ; i++){
            Xor ^= arr[i];
            
            if(!Xor){
                ans += i;
            }

            if(mp.contains(Xor)){
                auto [count, sum] = mp[Xor];
                ans += count * i - count - sum;
            }

            mp[Xor].first++;
            mp[Xor].second += i;
        }

        return ans;
    }
};
