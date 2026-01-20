class Solution {
    bool isValidRow(char n, int c, int r, vector<vector<char>>& board) {
        for (int col = 0; col < 9; col++) {
            if (col != c && board[r][col] == n)
                return false;
        }
        return true;
    }

    bool isValidCol(char n, int c, int r, vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            if (row != r && board[row][c] == n)
                return false;
        }
        return true;
    }

    bool isValidBox(char n, int c, int r, vector<vector<char>>& board) {
        int dc = c / 3 * 3;
        int dr = r / 3 * 3;
        for (int row = dr; row < dr + 3; row++) {
            for (int col = dc; col < dc + 3; col++) {
                if (!(col == c && row == r) && board[row][col] == n)
                    return false;
            }
        }
        return true;
    }

    bool isValidNum(char n, int c, int r, vector<vector<char>>& board) {
        if (!isValidCol(n, c, r, board))
            return false;
        if (!isValidRow(n, c, r, board))
            return false;
        if (!isValidBox(n, c, r, board))
            return false;
        return true;
    }

public:
    bool sl(int r, vector<vector<char>>& board) {
        for (int y = r; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                if (board[y][x] != '.')
                    continue;
                for (char n = '1'; n <= '9'; n++) {
                    if (isValidNum(n, x, y, board)) {
                        board[y][x] = n;
                        if (sl(y, board) == true)
                            return true;
                        board[y][x] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { sl(0, board); }
};
