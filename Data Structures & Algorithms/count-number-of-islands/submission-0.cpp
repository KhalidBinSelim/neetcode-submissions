class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < grid.size() &&
                ncol >= 0 && ncol < grid[0].size() &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int cnt = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
