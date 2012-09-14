#include <cstdio>

const int MAXN = 128;
const long long MOD = 10000007LL;

long long com[MAXN][MAXN], fac[MAXN], cnt[MAXN];

void init() {
    fac[0] = com[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        com[i][0] = com[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
        }
    }
    cnt[0] = 1;
    cnt[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        cnt[i] = 0;
        for (int j = 2; j <= i; ++j) {
            cnt[i] += com[i - 1][j - 1] * fac[j - 1] % MOD * cnt[i - j] % MOD;
        }
        cnt[i] %= MOD;
    }
}

int main() {
    int n, m, mm;
    char buf[MAXN];
    int f[MAXN], t[MAXN];
    long long ans;

    init();
    while (scanf("%d", &n) != EOF && n > 0) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = t[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            for (int j = 0; j < n; ++j) {
                if (buf[j] == 'Y') {
                    if (t[i] == -1 && f[j] == -1) {
                        t[i] = j;
                        f[j] = i;
                    } else {
                        ans = -1;
                    }
                }
            }
        }

        if (ans == -1) {
            puts("0");
        } else {
            m = mm = 0;
            for (int i = 0; i < n; ++i) {
                if (f[i] == -1) {
                    ++m;
                    if (t[i] != -1) {
                        ++mm;
                    }
                }
            }
            for (int i = 0; i <= mm; ++i) {
                ans = (ans + com[mm][i] * cnt[m - i]) % MOD;
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2157548   2010-04-12 21:55:08     Accepted    3319    C++     0   308     watashi@Zodiac

// 2012-09-07 02:07:32 | Accepted | 3319 | C++ | 0 | 308 | watashi | Source
