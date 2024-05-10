class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, vector<int>>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = n-1 ; j > i ; j--){
                ans.push_back({double((double)arr[i]/(double)arr[j]), {arr[i], arr[j]}});
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};
