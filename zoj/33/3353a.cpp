#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 15 * 16;
const int INF = 10000;

const char* _pat[] = {
    ".*. **. .** .**",
    "*** *** *** **.",
    ".*. *.. .*. .**",
};
vector<pair<int, int> > pat[4];
int ones[1 << 15];

void init() {
    for (int k = 0; k < 4; ++k) {
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                if (_pat[1 + x][4 * k + 1 + y] == '*') {
                    pat[k].push_back(make_pair(-x, -y));
                }
            }
        }
    }
    ones[0] = 0;
    for (int i = 1; i < (1 << 15); ++i) {
        ones[i] = ones[i >> 1] + (i & 1);
    }
}

int gao(int n, bool a[MAXN][MAXN], bool b[MAXN]) {
    int kk = n;
    for (int k = 0; k < n; ++k) {
        int ii = -1, jj = -1;
        for (int i = k; ii && -1 && i < n; ++i) {
            for (int j = k; jj == -1 && j < n; ++j) {
                if (a[i][j] == true) {
                    ii = i;
                    jj = j;
                }
            }
        }
        if (ii == -1 && jj == -1) {
            kk = k;
            break;
        }

        if (ii != k) {
            swap(b[k], b[ii]);
            for (int j = k; j < n; ++j) {
                swap(a[k][j], a[ii][j]);
            }
        }
        if (jj != k) {
            for (int i = 0; i < n; ++i) {
                swap(a[i][k], a[i][jj]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i == k || !a[i][k]) {
                continue;
            }
            b[i] ^= b[k];
            for (int j = k; j < n; ++j) {
                a[i][j] ^= a[k][j];
            }
        }
    }

    for (int k = kk; k < n; ++k) {
        if (b[k]) {
            return INF;
        }
    }

    vector<int> v(kk);
//  printf("kk = %d\n", kk);
    for (int i = 0; i < kk; ++i) {
        for (int j = kk; j < n; ++j) {
            if (a[i][j]) {
                v[i] |= 1 << (j - kk);
            }
        }
//      printf("v[%d] = %o; b[%d] = %d\n", i, v[i], i, b[i]);
    }

    int ret = INF;
    for (int i = 0; i < (1 << (n - kk)); ++i) {
        int tmp = ones[i];
        for (int j = 0; j < kk; ++j) {
            tmp += (ones[v[j] & i] + b[j]) % 2;
        }
        ret = min(ret, tmp);
    }
    return ret;
}

int main() {
    int n, r, c, x, y, tmp, idx, ans;
    char buf[20][20];
    bool a[MAXN][MAXN], b[MAXN];

    init();
    while (scanf("%d%d", &r, &c) != EOF && r > 0) {
        n = r * c;
        for (int i = 0; i < r; ++i) {
            scanf("%s", buf[i]);
        }

        ans = INF;
        for (int k = 0; k < 4; ++k) {
//          printf("gao %d:\n", k);
            memset(a, false, sizeof(a));
            memset(b, false, sizeof(b));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (buf[i][j] == '1') {
                        b[i * c + j] = true;
                    }
                    for (vector<pair<int, int> >::const_iterator it = pat[k].begin(); it != pat[k].end(); ++it) {
                        x = i + it->first;
                        y = j + it->second;
                        if (0 <= x && x < r && 0 <= y && y < c) {
                            a[i * c + j][x * c + y] = true;
                        }
                    }
                }
            }
            tmp = gao(n, a, b);
            if (ans > tmp) {
                ans = tmp;
                idx = k + 1;
            }
        }

        if (ans < INF) {
            printf("%d %d\n", idx, ans);
        } else {
            puts("Impossible");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//618   2010-07-17 00:44:10     Accepted    1078    C++     790     308     anotherpeg  Source

// 2012-09-07 15:47:50 | Accepted | 3353 | C++ | 490 | 308 | watashi | Source
