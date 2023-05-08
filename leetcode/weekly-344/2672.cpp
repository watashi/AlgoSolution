class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> c(n, 0);
        vector<int> ret;
        int cnt = 0;
        for (const auto& q: queries) {
            int k = q[0], v = q[1];
            if (c[k] != v) {
                if (c[k] != 0) {
                    if (k > 0 && c[k] == c[k - 1]) {
                        --cnt;
                    }
                    if (k + 1 < n && c[k] == c[k + 1]) {
                        --cnt;
                    }
                }
                c[k] = v;
                if (k > 0 && c[k] == c[k - 1]) {
                    ++cnt;
                }
                if (k + 1 < n && c[k] == c[k + 1]) {
                    ++cnt;
                }
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
