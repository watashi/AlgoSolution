class Solution {
public:
    long long maximumBeauty(vector<int>& v, long long newFlowers, int target, int full, int partial) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int64_t> s(n + 1);
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            v[i] = min(v[i], target);
            s[i + 1] = s[i] + v[i];
        }
        int64_t tt = target, ff = full, pp = partial;
        if (v[0] == target) {
            return ff * n;            
        }

        int64_t ans = 0;
        for (int i = n; i >= 0; --i) {
            int64_t tmp = ff * (n - i);
            int64_t rem = newFlowers;
            rem -= tt * (n - i) - (s[n] - s[i]);
            // cout << "[" << i << "] " << tt * (n - i) - (s[n] - s[i]) << endl;
            if (rem < 0) {
                break;
            }
            if (i > 0) {
                int lo = 0, hi = target;
                while (lo < hi) {
                    int mi = (lo + hi) / 2;
                    int j = lower_bound(v.begin(), v.begin() + i, mi) - v.begin();
                    if ((int64_t)mi * j - s[j] <= rem) {
                        lo = mi + 1;
                    } else {
                        hi = mi;
                    }
                }
                tmp += pp * (hi - 1);
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
