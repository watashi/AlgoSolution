#include <cctype>
#include <cstdio>
#include <cstring>

char buf[10001];
char* seven = "seven";
unsigned long long dp[10001][5];

int main() {
    while (gets(buf) != NULL) {
        dp[0][0] = (buf[0] == 's' || buf[0] == 'S');
        for (int j = 1; j < 5; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; buf[i]; ++i) {
            buf[i] = tolower(buf[i]);
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
            if (buf[i] == 's') {
                ++dp[i][0];
            }
            for (int j = 1; j < 5; ++j) {
                if (buf[i] == seven[j]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        printf("%llu\n", dp[strlen(buf)-1][4]);
    }
    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801345   2009-03-23 23:32:02     Accepted    3171    C++     10  576     watashi@Zodiac

// 2012-09-07 02:05:49 | Accepted | 3171 | C++ | 10 | 580 | watashi | Source
