class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);
        for (const auto& v: piles) {
            int ss = 0;
            vector<int> s;
            s.push_back(ss);
            for (int i: v) {
                ss += i;
                s.push_back(ss);
            }
            for (int i = k; i >= 0; --i) {
                for (int j = 1; j < (int)s.size() && j <= i; ++j) {
                    dp[i] = max(dp[i], dp[i - j] + s[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
