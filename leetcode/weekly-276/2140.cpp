class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = (int)q.size();
        vector<int64_t> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], dp[min(n, i + q[i][1] + 1)] + q[i][0]);
        }
        return dp[0];
    }
};
