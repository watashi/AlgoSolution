class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        const int dx[4] = {0, 1, 1, 1};
        const int dy[4] = {1, 0, 1, -1};
        int r = M.size(), c = M[0].size();
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!value(M, i, j)) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    if (!value(M, i - dx[k], j - dy[k])) {
                        int tmp = 0, x = i, y = j;
                        do {
                            x += dx[k];
                            y += dy[k];
                            ++tmp;
                        } while (value(M, x, y));
                        ans = max(ans, tmp);
                    }
                }
            }
        }
        return ans;
    }

    bool value(vector<vector<int>>& M, int x, int y) {
        int r = M.size(), c = M[0].size();
        return 0 <= x && x < r && 0 <= y && y < c && M[x][y] != 0;
    }
};
