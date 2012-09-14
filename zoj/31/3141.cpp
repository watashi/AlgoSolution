#include <cstring> // auto fix CE
#include <cstdio>
#include <algorithm>

using namespace std;

static int dp[1024][1024];

int gao(int r, int c)
{
    int& ret = dp[r][c];

    if (ret != -1) {
        return ret;
    }
    else if (r % c == 0) {
        return ret = r / c - 1;
    }
    else if (c % r == 0) {
        return ret = c / r - 1;
    }
    else {
        ret = 2 * r * c;
        for (int i = 1; i + i <= r; i++) {
            ret = min(ret, gao(i, c) + gao(r - i, c) + 1);
        }
        for (int i = 1; i + i <= c; i++) {
            ret = min(ret, gao(r, i) + gao(r, c - i) + 1);
        }
        return ret;
    }
}

int main() {
    int n, r, c;

    memset(dp, 0xff, sizeof(dp));
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &r, &c);
        printf("%d\n", gao(r, c));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750176   2009-01-28 15:12:51     Accepted    3141    C++     120     4272    watashi@Zodiac

// 2012-09-07 13:37:48 | Accepted | 3141 | C++ | 120 | 4276 | watashi | Source
