class NumMatrix {
private:
    vector<vector<int>> prefix_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix_sum = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        
        for (int r = 0; r < rows; r++) {
            int row_sum = 0;
            for (int c = 0; c < cols; c++) {
                row_sum += matrix[r][c];
                int above = prefix_sum[r][c + 1];
                prefix_sum[r + 1][c + 1] = row_sum + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = prefix_sum[row2][col2];
        int above = prefix_sum[row1 - 1][col2];
        int left = prefix_sum[row2][col1 - 1];
        int topLeft = prefix_sum[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};