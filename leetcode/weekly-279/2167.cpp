class Solution {
public:
    int minimumTime(string s) {
        int n = (int)s.size();
        int ans = n;
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '1') {
                ++y;
                if (2 * y >= i - x) {
                    x = i;
                    y = 0;
                }
            }
            ans = min(ans, x + 2 * y + (n - i));
        }
        return ans;
    }
};
