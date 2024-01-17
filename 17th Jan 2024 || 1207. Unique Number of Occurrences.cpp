class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n=arr.size();
        unordered_map<int,int> mp;
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto it: mp){
            int freq= it.second; 
            st.insert(freq);
        }

        return st.size() == mp.size();
        
    }
};
