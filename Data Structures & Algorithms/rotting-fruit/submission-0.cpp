class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<pair<int, int>, int>> Q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    Q.push({{i, j}, 0});
                }
            }
        }
        while (!Q.empty()) {
            auto it = Q.front();
            Q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int t = it.second;
            // top
            ans = max(ans, t);
            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
                Q.push({{i-1,j},t+1});
                vis[i-1][j] = 1;
            }
            // right
            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                Q.push({{i, j + 1}, t + 1});
                vis[i][j + 1] = 1;
            }
            // bottom
            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                Q.push({{i + 1, j}, t + 1});
                vis[i + 1][j] = 1;
            }
            // left
            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                Q.push({{i, j - 1}, t + 1});
                vis[i][j - 1] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};