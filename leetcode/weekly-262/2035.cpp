class Solution {
public:
    static constexpr int INF = 1000000007;

    static vector<vector<int>> go(int n, const int a[]) {
        vector<vector<int>> ret(n + 1);
        vector<int> s(1 << n);
        ret[0].emplace_back(0);
        for (int i = 1; i < (1 << n); ++i) {
            int k = __builtin_ctz(i);
            s[i] = s[i & (i - 1)] + a[k];
            ret[__builtin_popcount(i)].emplace_back(s[i]);
        }
        for (auto& i: ret) {
            sort(i.begin(), i.end());
            i.erase(unique(i.begin(), i.end()), i.end());
        }
        return ret;
    }

    int minimumDifference(vector<int>& nums) {
        int n = (int)nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int half = total / 2;
        auto x = go(n, nums.data());
        auto y = go(n, nums.data() + n);
        int ans = INF;
        for (int m = 0; m <= n; ++m) {
            const auto& yy = y[m];
            int j = (int)yy.size() - 1;
            for (int i: x[n - m]) {
                // auto jt = upper_bound(y[m].begin(), y[m].end(), half - i);
                while (j > 0 && yy[j - 1] > half - i) {
                    --j;
                }
                ans = min(ans, abs(total - 2 * (i + yy[j])));
                if (j > 0) {
                    ans = min(ans, abs(total - 2 * (i + yy[j - 1])));
                }
            }
        }
        return ans;
    }
};
