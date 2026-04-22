class NumMatrix {
private:
    vector<vector<int>> prefix_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix_sum = vector<vector<int>>(rows, vector<int>(cols, 0));
        
        for (int r = 0; r < rows; r++) {
            prefix_sum[r][0] = matrix[r][0];
            for (int c = 1; c < cols; c++) {
                prefix_sum[r][c] = prefix_sum[r][c - 1] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int r = row1; r <= row2; r++) {
            if (col1 > 0)
                ans += prefix_sum[r][col2] - prefix_sum[r][col1 - 1];
            else
                ans += prefix_sum[r][col2];
        }
        return ans;
    }
};