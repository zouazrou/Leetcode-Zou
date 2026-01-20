class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;
                if (isValidCell(c, r, board[r][c]))
                    setNum(c, r, board[r][c]);
                else
                    return false;
            }
        }
        return true;
    }

private:
    int col[9][10] = {0};
    int row[9][10] = {0};
    int box[9][10] = {0};
    bool isValidCell(int c, int r, char n) {

        int idx = (c / 3) + (r / 3) * 3;
        return (col[c][n - '0'] + row[r][n - '0'] + box[idx][n - '0'] == 0);
    }

    void setNum(int c, int r, char n) {
        int idx = (c / 3) + (r / 3) * 3;
        col[c][n - '0']++;
        row[r][n - '0']++;
        box[idx][n - '0']++;
    }
};
