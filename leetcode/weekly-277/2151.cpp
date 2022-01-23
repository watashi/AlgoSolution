class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int n = (int)s.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            bitset<16> bs(i);
            if (bs.count() <= ans) {
                continue;
            }
            bool ok = true;
            for (int j = 0; ok && j < n; ++j) {
                if (!bs.test(j)) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (s[j][k] != 2 && bs.test(k) != (s[j][k] == 1)) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ans = bs.count();
            }
        }
        return ans;
    }
};
