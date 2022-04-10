class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int64_t x = 0, n = 0;
        for (int i: v) {
            if ((i - x) * n <= k) {
                k -= (i - x) * n;
                x = i;
                ++n;
            } else {
                break;
            }
        }
        // cout << n << " " << x << endl;
        fill(v.begin(), v.begin() + n, x);
        for (int i = 0; i < n; ++i) {
            v[i] += k / n;
            if (i < k % n) {
                ++v[i];
            }
        }
        int64_t ans = 1;
        for (int i: v) {
            ans *= i;
            ans %= 1000000007;
        }
        return (int)ans;
    }
};
