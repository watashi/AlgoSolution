class Solution {
public:
    int minDistance(string a, string b) {
        vector<vector<int>> dp(
            a.size() + 1,
            vector<int>(b.size() + 1, 0));
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < (int)b.size(); ++j) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return a.size() + b.size() - 2 * dp[a.size()][b.size()];
    }
};
