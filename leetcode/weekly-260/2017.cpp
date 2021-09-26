class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int64_t> x, y;
        x.push_back(0);
        y.push_back(0);
        for (int i = 0; i < n; ++i) {
            x.push_back(x[i] + grid[0][n - 1 - i]);
            y.push_back(y[i] + grid[1][i]);
        }
        reverse(x.begin(), x.end());
        int64_t ans = x[0] + y[n];
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(x[i + 1], y[i]));
        }
        return ans;
    }
};
