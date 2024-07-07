class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int curr = numBottles;
        int ans = curr;
        while(curr >= numExchange){
            int newBottles = curr/numExchange;
            ans += newBottles;
            curr = newBottles + (curr % numExchange);
        }
        return ans;
    }
};
