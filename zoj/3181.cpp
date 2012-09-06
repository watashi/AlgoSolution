#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 1004;
const int MOD = 1000000007;

void kmp(char s[], char p[], int cover[MAXL][MAXL]) {
    int fail[MAXL];
    fail[0] = -1;
    for (int i = 1; p[i] != '\0'; ++i) {
        int k = fail[i - 1];
        while (k >= 0 && p[k + 1] != p[i]) {
            k = fail[k];
        }
        fail[i] = (p[k + 1] == p[i]) ? k + 1 : -1;
    }

    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] == p[j]) {
            ++i;
            ++j;
            if (p[j] == '\0') {
                ++cover[i - j][i];
                j = fail[j - 1] + 1;
            }
        } else if (j > 0) {
            j = fail[j - 1] + 1;
        } else {
            ++i;
        }
    }
}

int main() {
    int re, n, l;
    char str[MAXL], pat[MAXL];
    int sum[MAXL], all, tmp;
    int cover[MAXL][MAXL];

    scanf("%d ", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s%d ", str, &n);
        l = strlen(str);
        for (int i = 0; i < l; ++i) {
            sum[i] = 0;
            for (int j = 0; j <= l; ++j) {
                cover[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            gets(pat);
            kmp(str, pat, cover);
        }
        sum[l] = 1;
        for (int i = l - 1; i >= 0; --i) {
            all = 0;
            for (int j = min(l, i + 202); j > i; --j) {
                if (cover[i][j] > 0) {
                    tmp = ((long long)cover[i][j] * (long long)sum[j]) % MOD;
                }
                sum[j] = (sum[j] + all) % MOD;
                if (cover[i][j] > 0) {
                    all = (all + tmp) % MOD;
                }
            }
        }
        printf("%d\n", all);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1802877   2009-03-25 05:51:06     Accepted    3181    C++     640     4120    watashi@Zodiac

// int

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1802880   2009-03-25 05:53:51     Accepted    3181    C++     320     176     watashi@Zodiac
//1802879   2009-03-25 05:53:42     Accepted    3181    C++     310     176     watashi@Zodiac

// 2012-09-07 04:02:04 | Accepted | 3181 | C++ | 300 | 180 | watashi | Source
