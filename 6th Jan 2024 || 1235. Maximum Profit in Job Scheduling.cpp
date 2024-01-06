class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = profit.size();

        // sort jobs by endTime
        vector<int> sortedIdxes(size);
        for (int idx = 0; idx < size; ++idx) sortedIdxes[idx] = idx;
        sort(sortedIdxes.begin(), sortedIdxes.end(), [&endTime](int x, int y) { return endTime[x] < endTime[y]; });
        sortByIndexes(startTime, sortedIdxes);
        sortByIndexes(endTime, sortedIdxes);
        sortByIndexes(profit, sortedIdxes);

        vector<int> dp(size, 0);                // dp[i] is the maximiun profit to schedule job[0,...i]
        dp[0] = profit[0];
        for (int idx = 1; idx < size; ++idx) {  // iterate to add job[idx] into job scheduling
            int limit = startTime[idx];         // the maximum endTime for previous jobs
            int pos = upper_bound(endTime.begin(), endTime.begin() + idx, limit) - endTime.begin() - 1; // endTime[pos] <= limit
            int p = pos == -1 ? profit[idx] : profit[idx] + dp[pos];    // p: the maximum profit to include job[idx]
            dp[idx] = max(dp[idx - 1], p);                              // dp[idx - 1]: the maximum to not include job[idx]
        }

        return dp[size - 1];
    }

    void sortByIndexes(vector<int>& vec, vector<int>& idxes) {
        int size = idxes.size();
        vector<int> ret(size);
        for (int idx = 0; idx < size; ++idx) {
            ret[idx] = vec[idxes[idx]];
        }
        swap(ret, vec);
    }
};
