class Solution {
public:
    int maximumANDSum(vector<int>& nums, int m) {
        static int TRI[10];
        TRI[0] = 1;
        for (int i = 1; i < 10; ++i) {
            TRI[i] = TRI[i - 1] * 3;
        }

        vector<int> dp(TRI[m]);
        for (int x: nums) {
            vector<int> pre(TRI[m]);
            pre.swap(dp);
            for (int i = 0; i < TRI[m]; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i / TRI[j] % 3 != 2) {
                        dp[i + TRI[j]] = max(dp[i + TRI[j]], pre[i] + ((j + 1) & x));
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
