class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int64_t MOD = 1000000007;
        const int dx[4] = {1, 0, -1, 0};
        const int dy[4] = {0, 1, 0, -1};
        int64_t pre[60][60], cur[60][60];
        memset(cur, 0, sizeof(cur));
        cur[i][j] = 1;
        int64_t ans = 0;
        for (int xx = 0; xx < N; ++xx) {
            memcpy(pre, cur, sizeof(cur));
            memset(cur, 0, sizeof(cur));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int ii = i + dx[k];
                        int jj = j + dy[k];
                        if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                            cur[ii][jj] += pre[i][j];
                            if (cur[ii][jj] >= MOD) {
                                cur[ii][jj] -= MOD;
                            }
                        } else {
                            ans += pre[i][j];
                            if (ans >= MOD) {
                                ans -= MOD;
                            }
                        }
                    }
                }
            }
        }
        return (int)ans;
    }
};
