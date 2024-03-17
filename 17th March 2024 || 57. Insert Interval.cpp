class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int flag=1;

        for(int i=0;i<intervals.size();i++){
            if(newInterval[0]<=intervals[i][0]){
                flag=0;
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }

        if(flag){
            intervals.insert(intervals.end(),newInterval);
        }
        
        vector<vector<int>> ans;

        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
               end=max(end,intervals[i][1]);
            }
            else {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
