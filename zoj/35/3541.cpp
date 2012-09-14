#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <numeric>

using namespace std;

const int MAXN = 218;
const int INF = 1000000007;
int t[MAXN], d[MAXN];
int dp[MAXN][MAXN][2], pre[MAXN][MAXN][2];

int gao(int l, int r, int p) {
    int tmp, add;
    int& ret = dp[l][r][p];

    if (ret == -1) {
        if (l == r) {
            ret = 0;
        } else {
            ret = INF;
            tmp = d[l + 1] - d[l] + gao(l + 1, r, 0);
            add = p == 0 ? 0 : d[r] - d[l];
            if (t[l] > tmp && ret > tmp + add) {
                ret = tmp + add;
                pre[l][r][p] = 0;
            }
            tmp = d[r] - d[r - 1] + gao(l, r - 1, 1);
            add = p == 1 ? 0 : d[r] - d[l];
            if (t[r] > tmp && ret > tmp + add) {
                ret = tmp + add;
                pre[l][r][p] = 1;
            }
        }
    }

    return ret;
}

void dump(int l, int r, int p) {
    if (l == r) {
        printf("%d\n", l + 1);
    } else if (pre[l][r][p] == 0) {
        printf("%d ", l + 1);
        dump(l + 1, r, 0);
    } else {
        printf("%d ", r + 1);
        dump(l, r - 1, 1);
    }
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        if (gao(0, n - 1, 0) == INF) {
            puts("Mission Impossible");
        } else {
            dump(0, n - 1, 0);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675325   2011-10-02 20:08:27     Accepted    3541    C++     120     924     watashi     Source

// 2012-09-07 16:04:44 | Accepted | 3541 | C++ | 120 | 924 | watashi | Source
