class Solution {
public:
    int largestInteger(int num) {
        vector<bool> v;
        vector<int> o, e;
        while (num > 0) {
            int d = num % 10;
            if (d % 2 == 0) {
                e.push_back(d);
            } else {
                o.push_back(d);
            }
            v.push_back(d % 2 == 0);
            num /= 10;
        }
        reverse(v.begin(), v.end());
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        int ret = 0;
        for (auto i: v) {
            ret *= 10;
            if (i) {
                ret += e.back();
                e.pop_back();
            } else {
                ret += o.back();
                o.pop_back();
            }
        }
        return ret;
    }
};
