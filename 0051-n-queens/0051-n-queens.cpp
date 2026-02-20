class Solution {
public:
    vector<vector<string>> ans;
    vector<string> grid;
    vector<bool> rows;
    vector<bool> cols;
    vector<bool> up2down;
    vector<bool> down2up;

    bool isValid(int r, int c, int n) {
        if (rows[r])
            return false;
        if (cols[c])
            return false;
        if (down2up[r + c])
            return false;
        if (up2down[r - c + (n - 1)])
            return false;
        return true;
    }

    void df(int c, int n) {
        if (c == n) {
            ans.push_back(grid);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (!isValid(r, c, n))
                continue;
            grid[r][c] = 'Q';
            rows[r] = cols[c] = true;
            down2up[r + c] = up2down[r - c + (n - 1)] = true;
            df(c + 1, n);
            grid[r][c] = '.';
            rows[r] = cols[c] = false;
            down2up[r + c] = up2down[r - c + (n - 1)] = false;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++)
            grid.push_back(string(n, '.'));
        rows = vector<bool>(n, false);
        cols = vector<bool>(n, false);
        up2down = vector<bool>(n * 2 - 1, false);
        down2up = vector<bool>(n * 2 - 1, false);
        df(0, n);
        return ans;
    }
};