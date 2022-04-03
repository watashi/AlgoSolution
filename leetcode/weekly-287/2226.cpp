class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        int lo = 1, hi = *max_element(a.begin(), a.end()) + 1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            long long x = 0;
            for (int i: a) {
                x += i / mi;
            }
            if (x >= k) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return hi - 1;
    }
};
