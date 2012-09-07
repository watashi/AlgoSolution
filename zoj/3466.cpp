#include <cstdio>
#include <algorithm>

using namespace std;

const int ROW = 10;
const int COL = 8;
const int MAXN = 16;
const int MAXM = 1 << 16;
const int popcount[8] = {0, 1, 1, 2, 1, 2, 2, 3};
const int offset[8] = {13, 12, 9, 8, 5, 4, 1, 0};

long long tmp[MAXM], dp[MAXM];

void gao(int off, bool flag) {
    fill(tmp, tmp + MAXM, 0);
    for (int i = 0; i < MAXM; ++i) {
        if (dp[i] == 0) {
            continue;
        }
        int k = (i >> off) & 7;
        if (flag) {
            if (k == 0) {
                tmp[i] += dp[i];
            }
        } else {
            for (int j = 0; j < 8; ++j) {
                if (popcount[k] + popcount[j] == 2) {
                    tmp[i ^ ((k ^ j) << off)] += dp[i];
                }
            }
        }
    }
    copy(tmp, tmp + MAXM, dp);
}

int main() {
    int n, m;
    char buf[80];
    bool mark[ROW][COL];

    while (scanf("%d%d", &n, &m) != EOF) {
        fill(mark[0], mark[n], false);
        for (int i = 0; i < m; ++i) {
            scanf("%s", buf);
            mark[buf[0] - 'A'][buf[1] - 'A'] = true;
        }
        fill(dp, dp + MAXM, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < COL; j += 2) {
                gao(offset[j], mark[i][j]);
            }
            fill(tmp, tmp + MAXM, 0);
            for (int j = 0; j < MAXM; j += 2) {
                tmp[j >> 1] = dp[j];
            }
            copy(tmp, tmp + MAXM, dp);

            for (int j = 0; j < COL; j += 2) {
                gao(offset[j], mark[i][j]);
            }
            fill(tmp, tmp + MAXM, 0);
            for (int j = 0; j < MAXM / 2; ++j) {
                tmp[j << 1] = dp[j];
            }
            copy(tmp, tmp + MAXM, dp);
        }
        printf("%lld\n", dp[0]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//691   2011-01-30 15:36:22     Accepted    J   C++     740     1204    watashi@ArcOfDream  Source

// 2012-09-07 15:58:56 | Accepted | 3466 | C++ | 720 | 1204 | watashi | Source
