class Solution {
    int fx, fy;
    vector<vector<int>> dp;
    int sl(vector<vector<int>>& grid, int x, int y) {
        if (dp[y][x] != -1)
            return (dp[y][x]);
        if (x == fx && y == fy)
            return (grid[fy][fx]);
        int l = -1;
        int b = -1;
        int ans;
        if (!(x + 1 > fx))
            l = sl(grid, x + 1, y);
        if (!(y + 1 > fy))
            b = sl(grid, x, y + 1);
        if (l == -1)
            ans = b;
        else if (b == -1)
            ans = l;
        else
            ans = min(l, b);
        dp[y][x] = ans + grid[y][x];
        return ans + grid[y][x];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        fy = grid.size() - 1;
        fx = grid[0].size() - 1;
        dp.resize(fy + 1);
        for (int i = 0; i <= fy; i++)
            dp[i] = vector<int>(fx + 1, -1);
        return sl(grid, 0, 0);
    }
};