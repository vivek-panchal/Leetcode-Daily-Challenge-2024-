class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int i=0;
        int j = tokens.size()-1;
        int mx = 0, score = 0;
        sort(tokens.begin(),tokens.end());
        while(i<=j) {
            if(power>=tokens[i]) {
                power -= tokens[i];
                score++;
                mx = max(mx,score);
                i++;
            } else if(score>0) {
                power += tokens[j];
                score--;
                j--;
            } else {
                break;
            }
        }
        return mx;
    }
};
