class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int64_t lo = 0;
        int64_t hi = *min_element(time.begin(), time.end()) * (int64_t)totalTrips + 1;
        while (lo < hi) {
            int64_t mi = (lo + hi) / 2;
            int64_t s = 0;
            for (int64_t i: time) {
                s += mi / i;
            }
            if (s >= totalTrips) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }
};
