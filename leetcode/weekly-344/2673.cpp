class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> c;
        c.push_back(0);
        c.insert(c.end(), cost.begin(), cost.end());
        vector<int> d = c;
        for (int i = n / 2; i >= 1; --i) {
            d[i] += max(d[i * 2], d[i * 2 + 1]);
        }
        int ret = 0;
        for (int i = 2; i <= n; ++i) {
            ret += d[i / 2] - d[i] - c[i / 2];
        }
        return ret;
    }
};
