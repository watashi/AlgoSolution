class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n = (int)a.size();
        int m = (int)count(a.begin(), a.end(), 1);
        if (m == 0 || m == n) {
            return 0;
        }
        partial_sum(a.begin(), a.end(), a.begin());
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, a[i] + m - a[i + n - m]);
        }
        for (int i = m; i < n; ++i) {
            ans = max(ans, a[i] - a[i - m]);
        }
        return m - ans;
    }
};
