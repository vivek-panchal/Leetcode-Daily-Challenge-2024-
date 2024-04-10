class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end()); // o(nlogn)

        vector<int> output(n); 
        queue<int>  que;

        for(int i =0 ; i<n ;i++) que.push(i);

        int index = 0;

        while(!que.empty()){
            int top = que.front();
            output[top] = deck[index++];
            que.pop();

            if(!que.empty()){
                que.push(que.front());
                que.pop();
            }
        }
        return output;
    }
};
