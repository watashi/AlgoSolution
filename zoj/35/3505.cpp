#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30;
long long dp[30];

long long id(int n, char c, char* s) {
    if (*s == 0) {
        return 0;
    } else {
        long long m = 1;
        for (char i = '0'; i < *s; ++i) {
            if (i == c) {
                continue;
            }
            m += dp[n - 1];
        }
        m += id(n - 1, *s, s + 1);
        return m;
    }
}

void gao(int n, long long m, char c, char* s) {
    if (m == 0) {
        *s = '\0';
    } else {
        --m;
        for (*s = '0'; ; ++*s) {
            if (*s == c) {
                continue;
            }
            if (m < dp[n - 1]) {
                gao(n - 1, m, *s, s + 1);
                break;
            } else {
                m -= dp[n - 1];
            }
        }
    }
}

int main() {
    int n;
    long long m;
    char s[80];

    dp[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        dp[i] = dp[i - 1] * 3;
    }
    for (int i = 1; i < MAXN; ++i) {
        dp[i] += dp[i - 1];
    }

    while (scanf("%d%lld%s", &n, &m, s) != EOF) {
        m = id(n, '0', s) - m;
        gao(n, m, '0', s);
        puts(s);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//734   2011-04-26 22:25:13     Accepted    F   C++     60  180     watashi@ArcOfDream  Source

// 2012-09-07 16:03:00 | Accepted | 3505 | C++ | 60 | 180 | watashi | Source
