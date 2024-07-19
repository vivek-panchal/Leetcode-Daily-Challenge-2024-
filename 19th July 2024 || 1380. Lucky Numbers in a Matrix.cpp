class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rowMin;
        for(int i = 0; i < row; i++) {
            int rMin = matrix[i][0]; 
            for(int j = 0; j < col; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin); 
        }

        vector<int> colMax;
        for(int j = 0; j < col; j++) {
            int cMax = matrix[0][j]; 
            for(int i = 0; i < row; i++) {
                cMax = max(cMax, matrix[i][j]); 
            }
            colMax.push_back(cMax); 
        }

        vector<int> luckyNumbers;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};
