class Solution {
private:
    bool isOutBound(int r, int c, vector<vector<int>>& img) {
        return (r < 0 || c < 0 || r >= (int)img.size() ||
                c >= (int)img[0].size());
    }
    void BFS(vector<vector<int>>& img, int sr, int sc, int oldColor,
             int newColor) {
        int dc[] = {0, 0, 1, -1};
        int dr[] = {1, -1, 0, 0};
        int c, r;
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({sr, sc});
        visited.insert(q.back());
        while (!q.empty()) {
            pair<int, int>& currNode = q.front();
            if (img[q.front().first][q.front().second] == oldColor)
                img[q.front().first][q.front().second] = newColor;
            for (int i = 0; i < 4; i++) {
                r = currNode.first + dr[i];
                c = currNode.second + dc[i];
                if (!isOutBound(r, c, img) &&
                    visited.find({r, c}) == visited.end() &&
                    img[r][c] == oldColor) {
                    q.push({r, c});
                    visited.insert(q.back());
                }
            }
            q.pop();
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] != color)
            BFS(image, sr, sc, image[sr][sc], color);
        return (image);
    }
};