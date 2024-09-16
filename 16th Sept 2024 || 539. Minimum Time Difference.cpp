class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();
        vector<int> mini(n);

        for(int i=0;i<n;i++){

            string time = timePoints[i];
            string hours = time.substr(0,2);
            string mins = time.substr(3);

            int hour = stoi(hours);
            int min = stoi(mins);

            mini[i] = (hour*60 + min);
        }
        sort(mini.begin(), mini.end());

        int res = INT_MAX;
        for(int i=1;i<n;i++){
            res = min(res, mini[i] - mini[i-1]);
        }
        return min(res, 1440 - mini[n-1] + mini[0]);
    }
};
