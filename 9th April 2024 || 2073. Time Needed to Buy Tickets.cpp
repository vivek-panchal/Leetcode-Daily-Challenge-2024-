class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;

        // index upto k, each person will buy upto "tickets[k]"
        for(int i = 0; i <= k; i++) {
            count += (tickets[i] > tickets[k]) ? tickets[k] : tickets[i];
        }

        // index from k+1, each person will buy upto "tickets[k]-1"
        for(int i = k+1; i < tickets.size(); i++) {
            count += (tickets[i] > tickets[k]-1) ? tickets[k]-1 : tickets[i];
        }

        return count;
    }
};
