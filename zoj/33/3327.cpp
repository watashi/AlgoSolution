#include <cstdio>
#include <algorithm>

using namespace std;

enum { MAXN = 1024 };
typedef char bignum[MAXN];

int read(bignum b) {
    int n;
    scanf("%*[^0-9]");
    scanf("%[0-9]%n", b, &n);
    reverse(b, b + n);
    fill(b + n, b + MAXN, '0');
    return n;
}

void write(bignum b) {
    int i = MAXN - 1;
    while (i > 0 && b[i] == '0') {
        --i;
    }
    while (i >= 0) {
        putchar(b[i--]);
    }
    puts("");
}

void succ(bignum b) {
    for (int i = 0; ; ++i) {
        if (b[i] == '9') {
            b[i] = '0';
        } else {
            ++b[i];
            break;
        }
    }
}

int p[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {3, 0, 0, 0},
    {0, 2, 0, 0}
};

bool ok(int x[4], int y[4]) {
    for (int i = 0; i < 4; ++i) {
        if (x[i] < y[i]) {
            return false;
        }
    }
    return true;
}

void ko(int x[4], int y[4]) {
    for (int i = 0; i < 4; ++i) {
        x[i] -= y[i];
    }
}

int main() {
    int re, n, m, d, c[4];
    bignum b;

    scanf("%d", &re);
    for (int ri = 0; ri < re; ++ri) {
        n = read(b);
        m = count(b, b + n, '0');
        if (m == 0) {
            fill(c, c + 4, 0);
            for (int i = 0; i <= n; ++i) {
                d = b[i] - '0';
                for (int j = 0; j < 4; ++j) {
                    c[j] += p[d][j];
                }
                for (int j = d + 1; j < 10; ++j) {
                    if (ok(c, p[j])) {
                        b[i] = '0' + j;
                        ko(c, p[j]);
                        for (int k = 9, l = 0; k > 0; --k) {
                            while (l < i && ok(c, p[k])) {
                                b[l++] = '0' + k;
                                ko(c, p[k]);
                            }
                        }
                        d = -1;
                        break;
                    }
                }
                if (d == -1) {
                    break;
                }
            }
        } else if (m == 1 && b[0] == '0') {
            for (int i = 0; i < 10; ++i) {
                succ(b);
            }
        } else {
            succ(b);
        }
        write(b);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2172215   2010-04-21 20:06:41     Accepted    3327    C++     0   176     watashi@Zodiac

// 2012-09-07 02:08:15 | Accepted | 3327 | C++ | 0 | 180 | watashi | Source
