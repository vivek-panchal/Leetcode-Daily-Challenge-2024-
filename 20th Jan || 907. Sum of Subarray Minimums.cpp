class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack< pair<int,int> > st1, st2;
        int n = arr.size();
        vector<int> left(n), right(n);
        const int mod = 1e9 + 7;
        //initialize to avoid error if it is not initialized in the code;

        for(int i = 0; i < n; i++) {
            left[i] = i+1;
            right[i] = n-i;
        }

        for(int i = 0; i < n; i++) {
            //for ple previous less element;
            while( !st1.empty() && st1.top().first > arr[i]) {
                st1.pop();
            }
            left[i] = st1.empty() ? i + 1 : i - st1.top().second;
            st1.push({arr[i], i});

            //for nle next lesser element
            while( !st2.empty() && st2.top().first > arr[i]) {
                auto x = st2.top(); 
                st2.pop();
                right[x.second] = i - x.second;
            }
            st2.push({arr[i], i});
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans =  (ans + (long long)(arr[i] * left[i])* right[i])  % mod ;
        }

        return ans;
    }
};
