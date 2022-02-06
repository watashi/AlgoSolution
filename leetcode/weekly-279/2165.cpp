class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        vector<int> d;
        while (num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
        sort(d.begin(), d.end());
        if (neg) {
            reverse(d.begin(), d.end());
            long long ret = 0;
            for (auto i: d) {
                ret = ret * 10 + i;
            }
            return -ret;
        } else {
            auto it = find_if(d.begin(), d.end(), [](int i){ return i > 0; });
            swap(d[0], *it);
            long long ret = 0;
            for (auto i: d) {
                ret = ret * 10 + i;
            }
            return ret;
        }
    }
};
