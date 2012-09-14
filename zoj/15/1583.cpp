#include <cctype>
#include <cstdio>

int read() {
    static char buf[4 * 1024];
    static char *p = buf;

SKIP:
    while (*p != '\0' && !isdigit(*p)) {
        ++p;
    }
    if (*p == '\0') {
        gets(buf);
        p = buf;
        goto SKIP;
    } else {
        int ret = 0;
        do {
            ret *= 10;
            ret += *p - '0';
            ++p;
        } while (isdigit(*p));
        return ret;
    }
    /* NOREACHED */
}

int main() {
    int ri = 0;
    int n;
    /*static */int a[512][512], b[512][512];

    while ((n = read()) != 0) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] = read();
            }
        }
        for (int i = 1; i <= n; ++i) {
            b[i][1] = a[i][1];
            b[i][n] = a[i][n];
            b[1][i] = a[1][i];
            b[n][i] = a[n][i];
        }
        for (int i = 2; i < n; ++i) {
            for (int j = 2; j < n; ++j) {
                b[i][j] = ((a[i][j] << 2) +
                    ((a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1]) << 1) +
                    (a[i-1][j-1] + a[i-1][j+1] + a[i+1][j-1] + a[i+1][j+1]))
                    >> 4;
            }
        }
        printf("Case %d:\n", ++ri);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%d%c", b[i][j], j == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1755493   2009-02-04 02:18:02     Accepted    1583    C++     60  180     watashi@Zodiac

/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-02-04 02:18:02     C++     60  180     watashi@Zodiac
2008-12-18 07:55:23     C++     110     184     Dorm2-4106
2009-01-30 14:36:06     C++     120     2032    大家一起用java
2008-12-04 21:52:42     FPC     140     1980    lzh
2006-07-06 15:33:48     FPC     200     3332    光荣的炮灰
2006-07-06 15:35:19     FPC     200     3336    liuyi
2008-11-24 10:54:38     C++     210     2032    cs_xiaoli
2006-03-20 17:34:16     FPC     220     1380    ???
*/

// 2012-09-07 00:54:50 | Accepted | 1583 | C++ | 80 | 184 | watashi | Source
