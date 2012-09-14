#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int pre[MAXN][MAXN];
double tot[MAXN][MAXN];
long long rem[MAXN][MAXN];

const double EPS = 1e-8;

double lt(double lhs, double rhs) {
    return (rhs - lhs) / (rhs + lhs) > EPS;
}

int main() {
    int re, n, m, a[MAXN];
    double prod;
    long long base;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d%d%lld", &n, &m, &base) == 3);
        assert(1 <= n && n <= 100 && 1 <= m && m <= 100 && 2 <= base && base <= 1000000007);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d", &a[i]) == 1);
            assert(-10000 <= a[i] && a[i] <= 10000);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tot[i][j] = i == m - 1 ? 1 : 0;
                rem[i][j] = i == m - 1 ? 1 : 0;
                pre[i][j] = -1;
            }
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (tot[i + 1][j] == 0) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (a[j] <= a[k]) {
                        continue;
                    }
                    prod = tot[i + 1][j] * (a[j] - a[k]);
                //  if (tot[i][k] < prod || (tot[i][k] == prod && pre[i][k] > j)) {
                    if (lt(tot[i][k], prod) || (!lt(prod, tot[i][k]) && pre[i][k] > j)) {
                        tot[i][k] = prod;
                        rem[i][k] = rem[i + 1][j] * (a[j] - a[k]) % base;
                        pre[i][k] = j;
                    }
                }
            }
        }

        int p = max_element(tot[0], tot[0] + n) - tot[0];
        printf("%lld\n", rem[0][p]);
        if (tot[0][p] == 0) {
            for (int i = 0; i < m; ++i) {
                printf("%d%c", 0, i == m - 1 ? '\n' : ' ');
            }
        } else {
            for (int i = 0; i < m; ++i) {
                printf("%d%c", p, i == m - 1 ? '\n' : ' ');
                p = pre[i][p];
            }
        }
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//216   2011-04-03 01:10:07     Accepted    F   C++     130     500     watashi     Source

// 2012-09-07 16:00:34 | Accepted | 3482 | C++ | 90 | 500 | watashi | Source
