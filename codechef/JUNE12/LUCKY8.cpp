#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20;
const long long INF = 999999999999999998LL;

long long ten[MAXN];
long long cnt[MAXN][MAXN][MAXN];

void init() {
    ten[0] = 1;
    cnt[0][0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        ten[i] = ten[i - 1] * 10;
        for (int j = 0; j < MAXN; ++j) {
            for (int k = 0; k < MAXN; ++k) {
                cnt[i][j][k] = cnt[i - 1][j][k] * 8;
                if (j > 0) {
                    cnt[i][j][k] += cnt[i - 1][j - 1][k];
                }
                if (k > 0) {
                    cnt[i][j][k] += cnt[i - 1][j][k - 1];
                }
            }
        }
    }
}

long long gao(long long n, int x, int y) {
    long long m = 0;
    while (ten[m] <= n) {
        ++m;
    }
    long long ret = 0;
    while (m > 0 && x >= 0 && y >= 0) {
        --m;
        long long d = n / ten[m];
        switch (d) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            ret += d * cnt[m][x][y];
            break;
        case 5:
        case 6:
        case 7:
            ret += (d - 1) * cnt[m][x][y];
            if (x > 0) {
                ret += cnt[m][x - 1][y];
            }
            break;
        case 8:
        case 9:
            ret += (d - 2) * cnt[m][x][y];
            if (x > 0) {
                ret += cnt[m][x - 1][y];
            }
            if (y > 0) {
                ret += cnt[m][x][y - 1];
            }
            break;
        }
        n -= d * ten[m];
        if (d == 4) {
            --x;
        } else if (d == 7) {
            --y;
        }
    }
    return ret;
}

int main() {
    int re, ans;
    long long l, r;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld%lld", &l, &r);
        ans = 0;
        l = min(INF, l);
        r = min(INF, r);
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; i + j < MAXN; ++j) {
                if (i * j > ans && gao(r + 1, i, j) - gao(l, i, j) > 0) {
                    ans = i * j;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

