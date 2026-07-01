class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1,
                               vector<int>(matrix[0].size() + 1, 0));
        int ans = 0;
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                if (matrix[y][x] == '0')
                    continue;
                dp[y + 1][x + 1] = min(dp[y][x + 1], dp[y + 1][x]);
                dp[y + 1][x + 1] = min(dp[y + 1][x + 1], dp[y][x]) + 1;
                ans = max(ans, dp[y + 1][x + 1]);
            }
        }
        return ans * ans;
    }
};