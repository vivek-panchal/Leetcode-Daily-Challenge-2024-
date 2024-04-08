class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleCount = 0, squareCount = 0;
        int len = sandwiches.size();

        for (int i = 0; i < len; i++) {
            students[i] == 0 ? circleCount++ : squareCount++;
        }

        for (int i = 0; i < len; i++) {
            if (sandwiches[i] == 0 && circleCount == 0) {
                return squareCount;
            } else if (sandwiches[i] == 1 && squareCount == 0) {
                return circleCount;
            }
            sandwiches[i] == 0 ? circleCount-- : squareCount--;
        }

        return 0;
    }
};
