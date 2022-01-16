class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long lo = 0, hi = accumulate(batteries.begin(), batteries.end(), 0ll) + 1;
        while (lo < hi) {
            long long mi = (lo + hi) / 2;
            long long s = 0;
            for (long long i: batteries) {
                s += min(mi, i);
            }
            if (s >= mi * n) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return hi - 1;
    }
};
