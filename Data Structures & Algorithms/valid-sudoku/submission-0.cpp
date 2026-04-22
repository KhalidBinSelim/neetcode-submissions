class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> already_exists;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') {
                    continue;
                }
                if (already_exists.count(board[row][i])) {
                    return false;
                }
                already_exists.insert(board[row][i]);
            }
        }
        for (int col = 0; col < 9; col++) {
            unordered_set<char> already_exists;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') {
                    continue;
                }
                if (already_exists.count(board[i][col])) {
                    return false;
                } 
                already_exists.insert(board[i][col]);
            }
        }
        for (int little_matrix = 0; little_matrix < 9; little_matrix++) {
            unordered_set<char> already_exists;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (little_matrix / 3) * 3 + i;
                    int col = (little_matrix % 3) * 3 + j;
                    if (board[row][col] == '.') {
                        continue;
                    }
                    if (already_exists.count(board[row][col])) {
                        return false;
                    }
                    already_exists.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};