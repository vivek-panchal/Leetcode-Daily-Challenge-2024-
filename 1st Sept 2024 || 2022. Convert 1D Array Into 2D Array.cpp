class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if(m*n!=original.size()){
            return {};
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(original[(n*i)+j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
