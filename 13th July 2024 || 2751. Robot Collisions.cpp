class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices;
        stack<int> stack;

        for(int i = 0; i < n; i++){
            indices.push_back(i);
        }

        auto compare = [&](int id1, int id2){
            return positions[id1] <= positions[id2];
        };
        sort(indices.begin(), indices.end(), compare);

        for(auto i : indices){
            if(directions[i] == 'R'){
                stack.push(i);
            }
            else{
                while(!stack.empty() && healths[i] > 0){
                    if(healths[i] > healths[stack.top()]){
                        healths[i]--;
                        healths[stack.top()] = 0;
                        stack.pop();
                    }
                    else if(healths[i] < healths[stack.top()]){
                        healths[i] = 0;
                        healths[stack.top()]--;
                    }
                    else{
                        healths[i] = 0;
                        healths[stack.top()] = 0;
                        stack.pop();
                    }
                }
            }
        }

        vector<int> ans;
        for(int j = 0; j < n; j ++){
            if(healths[j] > 0){
                ans.push_back(healths[j]);
            }
        }
        return ans;
    }
};
