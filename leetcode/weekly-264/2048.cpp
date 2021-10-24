class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<vector<int>> vs = {
            {1},
            {2},
            {3},
            {1, 2},
            {4},
            {1, 3},
            {5},
            {1, 4},
            {2, 3},
            {6},
            {1, 5},
            {1, 2, 3},
            {2, 4},
        };
        int ret = 1224444;
        for (const auto& v: vs) {
            vector<int> ds;
            for (int i: v) {
                for (int j = 1; j <= i; ++j) {
                    ds.push_back(i);
                }
            }
            do {
                int m = 0;
                for (int d: ds) {
                    m *= 10;
                    m += d;
                }
                if (m > n) {
                    ret = min(ret, m);
                }
            } while (next_permutation(ds.begin(), ds.end()));
        }
        return ret;
    }
};
