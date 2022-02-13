class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long rem = accumulate(beans.begin(), beans.end(), 0LL);
        sort(beans.begin(), beans.end());
        long long n = beans.size(), sum = 0, ret = rem;
        for (long long i = 0; i < n; ++i) {
            ret = min(ret, rem - (n - i) * beans[i] + sum);
            sum += beans[i];
            rem -= beans[i];
        }
        return ret;
    }
};
