#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cctype>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <string>
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <cassert>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

struct People {
    string name;
    double u, d;
    double r, p, s;

    static int readInt() {
        static int t;
        assert(scanf("%d", &t) == 1);
        assert(0 <= t && t <= 100);
        return t;
    }

    void read() {
        static char buf[80];
        assert(scanf("%s", buf) == 1);
        name = buf;
        assert(name.length() <= 20);
        for (string::const_iterator c = name.begin(); c != name.end(); ++c) {
            assert(isalpha(*c));
        }

        static double t;
        u = readInt();
        d = readInt();
        t = u + d;
        assert(t > 0);
        u /= t;
        d /= t;

        r = readInt();
        p = readInt();
        s = readInt();
        t = r + p + s;
        assert(t > 0);
        r /= t;
        p /= t;
        s /= t;
    }
} info[32];

const int MAXN = 13;
const double EPS = 1e-8;

double lose[MAXN][MAXN];
double u[1 << MAXN], d[1 << MAXN], dp[1 << MAXN];
double popcnt[1 << MAXN], ctz[1 << MAXN];

void init() {
    for (int i = 0; i < (1 << MAXN); ++i) {
        popcnt[i] = __builtin_popcount(i);
        ctz[i] = __builtin_ctz(i);
    }
}

int main() {
    int re, n;
    double ans;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        assert(1 <= n && n <= 13);
        for (int i = 0; i < n; ++i) {
            info[i].read();
        }

        u[0] = d[0] = 1;
        for (int i = 1; i < (1 << n); ++i) {
            int z = ctz[i];
            u[i] = u[i ^ (1 << z)] * info[z].u;
            d[i] = d[i ^ (1 << z)] * info[z].d;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                lose[i][j] = info[i].r * info[j].p + info[i].p * info[j].s + info[i].s * info[j].r;
            }
        }

        //
        for (int i = 1; i < (1 << n); ++i) {
            if (popcnt[i] == 1) {
                dp[i] = 0;
            } else if (popcnt[i] == 2) {
                int x = ctz[i];
                int y = ctz[i ^ (1 << x)];
                dp[i] = 1 / (lose[x][y] + lose[y][x]);
            } else {
                double x = 0;
                double y = 1;
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    int k = i ^ j;
                    if (popcnt[j] != popcnt[k] && u[j] > 0 && d[k] > 0) {
                        x += u[j] * d[k];
                        y += u[j] * d[k] * dp[popcnt[j] < popcnt[k] ? j : k];
                    }
                }
                dp[i] = y / x;
            }
        //  printf("%d = %lf\n", i, dp[i]);
            assert(!isnan(dp[i]));
        }
        if (isinf(dp[(1 << n) - 1])) {
            printf("Infinity ");
        } else {
            printf("%.3lf ", dp[(1 << n) - 1]);
        }

        //
        ans = 0;
        fill(dp, dp + (1 << n), 0);
        dp[(1 << n) - 1] = 1;
        for (int i = (1 << n) - 1; i > 0; --i) {
            if (dp[i] == 0) {
                continue;
            }
            if (popcnt[i] == 1) {
                ans = max(ans, dp[i]);
            } else if (popcnt[i] == 2) {
                int x = ctz[i];
                int y = ctz[i ^ (1 << x)];
                if (lose[x][y] + lose[y][x] > 0) {
                    dp[1 << x] += lose[x][y] / (lose[x][y] + lose[y][x]) * dp[i];
                    dp[1 << y] += lose[y][x] / (lose[x][y] + lose[y][x]) * dp[i];
                }
            } else {
                double x = 0;
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    int k = i ^ j;
                    if (popcnt[j] != popcnt[k] && u[j] > 0 && d[k] > 0) {
                        x += u[j] * d[k];
                    }
                }
                if (x == 0) {
                    continue;
                }
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    int k = i ^ j;
                    if (popcnt[j] != popcnt[k] && u[j] > 0 && d[k] > 0) {
                        dp[popcnt[j] < popcnt[k] ? j : k] += u[j] * d[k] / x * dp[i];
                    }
                }
            }
        //  printf("%d = %lf\n", i, dp[i]);
            assert(isfinite(dp[i]));
        }
        printf("%.3lf%%\n", 100 * ans);

        vector<string> lst;
        for (int i = 0; i < n; ++i) {
            if (fabs(dp[1 << i] - ans) < EPS) {
                lst.push_back(info[i].name);
            }
        }
        sort(lst.begin(), lst.end());
        for (int i = 0; i < (int)lst.size(); ++i) {
            printf("%s%c", lst[i].c_str(), i == (int)lst.size() - 1 ? '\n' : ' ');
        }
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//472   2011-04-15 01:47:37     Accepted    G   C++     980     500     watashi     Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2     2011-04-15 23:03:51     Accepted    G   C++     740     504     watashi@ArcOfDream  Source

// 2012-09-07 16:01:47 | Accepted | 3493 | C++ | 740 | 504 | watashi | Source
