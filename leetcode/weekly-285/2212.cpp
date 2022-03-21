class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        constexpr int BITS = 12;
        pair<int, int> best(0, 0);
        for (int m = 0; m < (1 << BITS); ++m) {
            int s = 0;
            int c = 0;
            for (int i = 0; i < BITS; ++i) {
                if (m & (1 << i)) {
                    s += i;
                    c += aliceArrows[i] + 1;
                }
            }
            if (c <= numArrows) {
                best = max(best, make_pair(s, m));
            }
        }
        vector<int> ans(BITS, 0);
        int rem = numArrows;
        for (int i = 0; i < BITS; ++i) {
            if (best.second & (1 << i)) {
                ans[i] = aliceArrows[i] + 1;
                rem -= ans[i];
            }
        }
        ans[0] += rem;
        return ans;
    }
};
