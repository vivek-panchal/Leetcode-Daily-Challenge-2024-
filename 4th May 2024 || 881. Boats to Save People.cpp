class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                count++;
                i++;
                j--;
            }
            else{
                count++;
                j--;
            }
        }
        return count;
    }
};
