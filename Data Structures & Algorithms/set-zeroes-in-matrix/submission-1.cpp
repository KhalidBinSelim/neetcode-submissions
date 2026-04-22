class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) return;
        int numOfRow = matrix.size();
        int numOfCol = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int j = 0; j < numOfCol; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (int i = 0; i < numOfRow; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int i = 1; i < numOfRow; i++) {
            for (int j = 1; j < numOfCol; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < numOfRow; i++) {
            for (int j = 1; j < numOfCol; j++) {
                if (matrix[i][0] == 0 or matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < numOfCol; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < numOfRow; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};