#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>
#include <algorithm> // auto fix CE
#include <cstring>

const int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1};
const int dom[2][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool leap(int yy) {
    return yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0);
}

void show(char* p, int n, int v) {
    p += n;
    for (int i = 0; i < n; ++i) {
        *--p = '0' + v % 10;
        v /= 10;
    }
}

int diff(char* a, char* b) {
    int ret = 0;
    while (*a != '\0' || *b != '\0') {
        if (*a++ != *b++) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    int re, len;
    char buf[80], tmp[80], ans[80];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%s", buf) == 1);
        len = strlen(buf);
        assert(len == 15 || len == 18);

        strcpy(tmp, buf);
        memset(ans, '?', sizeof(ans));
        ans[len] = '\0';
        for (int y = 1900; y <= 2011; ++y) {
            if (len == 15) {
                show(tmp + 6, 2, y % 100);
            } else {
                show(tmp + 6, 4, y);
            }
            for (int m = 1; m <= (y == 2011 ? 4 : 12); ++m) {
                show(len == 15 ? tmp + 8 : tmp + 10, 2, m);
                for (int d = 1; d <= (y == 2011 && m == 4 ? 2 : dom[leap(y)][m]); ++d) {
                    show(len == 15 ? tmp + 10 : tmp + 12, 2, d);
                    if (len == 18) {
                        int s = 0;
                        for (int i = 0; i < 17; ++i) {
                            s += (tmp[i] - '0') * w[i];
                        }
                        s = (12 - s % 11) % 11;
                        tmp[17] = s == 10 ? 'X' : '0' + s;
                    }
                    if (diff(buf, ans) > diff(buf, tmp)) {
                        strcpy(ans, tmp);
                    }
                }
            }
        }
        puts(ans);
    }
    assert(scanf("%s", buf) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//219   2011-04-03 01:12:07     Accepted    I   C++     920     180     watashi     Source

// 2012-09-07 16:00:58 | Accepted | 3485 | C++ | 770 | 180 | watashi | Source
