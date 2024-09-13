class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> ans;

        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        for (auto &it : queries) {
            int left = it[0];
            int right = it[1];

            if (left == 0) {
                ans.push_back(prefix[right]);  
            } else {
                ans.push_back(prefix[right] ^ prefix[left - 1]); 
            }
        }

        return ans;
    }
};
