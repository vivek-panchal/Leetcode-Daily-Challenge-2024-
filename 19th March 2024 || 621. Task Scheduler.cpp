class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        
        int mx_cnt=0,mx_tasks=0;
        for(auto c: tasks) {
            cnt[c-'A']++;
            int cur_cnt = cnt[c-'A'];
            
            if(cur_cnt == mx_cnt){
                mx_tasks++;
            }
            else if(cur_cnt > mx_cnt){
                mx_cnt = cur_cnt;
                mx_tasks = 1;
            }
        }
        
        int total = (n+1)*(mx_cnt-1) + mx_tasks;
        int empty = total - mx_cnt*mx_tasks;
        int available = tasks.size() - mx_cnt*mx_tasks;
        
        if(empty < available) {
            return tasks.size();
        }
        else {
            return total;
        }
    }
};
