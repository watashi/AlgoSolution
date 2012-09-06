#include <cstdio>
#include <cstring>

typedef long long integer;
const integer NOT_INI = -1LL;
int n, len;
char a[32], b[32];
integer dp[32][32][32];

integer doit(int as, int bs, int ll)
{
    integer &ret = dp[as][bs][ll];

    if (ret != NOT_INI) {
        return ret;
    }
    else if (ll == 0) {
        return ret = 1;
    }
    else if (a[as] != b[bs + ll - 1]) {
        return ret = 0;
    }

    integer dpdp[32][32];

    ++as;
    --ll;
    for (int i = 0; i <= ll; i++) {
        for (int j = 0; j <= n; j++) {
            dpdp[i][j] = 0;
        }
    }
    dpdp[0][0] = 1;
    for (int i = 0; i <= ll; i++) {
        for (int j = i; j <= ll; j++) {
            integer t = doit(as + i, bs + i, j - i);
            for (int k = 0; k < n; k++) {
                dpdp[j][k + 1] += dpdp[i][k] * t;
            }
        }
    }

    return ret = dpdp[ll][n];
}

int main(void)
{
    while (scanf("%d", &n) != EOF && n > 0) {
        scanf("%s%s", a, b);
        len = strlen(a);
        for (int i = 0; i <= len; i++)
            for (int j = 0; j <= len; j++)
                for (int k = 0; k <= len; k++)
                    dp[i][j][k] = NOT_INI;
        printf("%lld\n", doit(0, 0, len));
        /*      {
        int aa, bb, cc;
        while (scanf("%d%d%d", &aa, &bb, &cc) != EOF) {
        printf("%llu\n", dp[aa][bb][cc]);
        }
        }
        */
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2973022   2008-07-12 12:21:23     Accepted    1500    C++     00:00.02    912K    Re:ReJudge

// 2012-09-07 00:51:10 | Accepted | 1500 | C++ | 10 | 436 | watashi | Source
