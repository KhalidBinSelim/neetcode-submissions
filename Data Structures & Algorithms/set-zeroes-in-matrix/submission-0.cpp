class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numOfRow = matrix.size(), numOfCol = matrix[0].size();
        vector<int> row(numOfRow, 0);
        vector<int> col(numOfCol, 0);
        for (int i = 0; i < numOfRow; i++) {
            for (int j = 0; j < numOfCol; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < numOfRow; i++) {
            for (int j = 0; j < numOfCol; j++) {
                if (row[i] == 1 or col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};