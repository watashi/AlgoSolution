class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        static constexpr int64_t INF = 9876543210;
        static constexpr int MAXL = 30;
        vector<int64_t> v(MAXL + 1, INF);
        for (const auto& i : tires) {
            int64_t f = i[0];
            int64_t r = i[1];
            int64_t s = 0;
            for (int i = 1; i <= MAXL && f <= INF; ++i) {
                s += f;
                v[i] = min(v[i], s);
                f *= r;
            }
        }
        vector<int64_t> dp(numLaps + 1, INF);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j <= MAXL && j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j] + v[j] + changeTime);
            }
        }
        return dp.back();
    }
};
