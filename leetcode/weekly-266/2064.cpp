class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int lo = 1, hi = *max_element(q.begin(), q.end()) + 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int c = n;
            for (int i: q) {
                c -= (i + mi - 1) / mi;
                if (c < 0) {
                    break;
                }
            }
            if (c < 0) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return hi;
    }
};
