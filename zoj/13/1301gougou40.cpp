#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define BIN(i) (1 << (i))

const int MAXN = 10;
const int MASK = BIN(MAXN) - 1;

int main() {
    int ri = 0, n, m, l, a, b;
    vector<int> d[MAXN];
    vector<int> s[MAXN];
    int pre[MAXN][BIN(MAXN)];
    int mind[MAXN][BIN(MAXN)];
    int q[MAXN * BIN(MAXN)];

    while (scanf("%d%d%d", &n, &m, &l) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            d[i].clear();
            s[i].clear();
            fill(mind[i], mind[i] + BIN(n), -1);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            d[a - 1].push_back(b - 1);
            d[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < l; ++i) {
            scanf("%d%d", &a, &b);
            if (a != b) {
                s[a - 1].push_back(b - 1);
            }
        }

        mind[0][BIN(0)] = 0;
        q[0] = (0 << MAXN) ^ BIN(0);
        for (int begin = 0, end = 1; begin < end && mind[n - 1][BIN(n - 1)] == -1; ++begin) {
            int x = q[begin] >> MAXN;
            int y = q[begin] & MASK;
            for (vector<int>::const_iterator i = d[x].begin(); i != d[x].end(); ++i) {
                if ((y & BIN(*i)) != 0 && mind[*i][y] == -1) {
                    mind[*i][y] = mind[x][y] + 1;
                    pre[*i][y] = -1 - x;
                    q[end++] = (*i << MAXN) ^ y;
                }
            }
            for (vector<int>::const_iterator i = s[x].begin(); i != s[x].end(); ++i) {
                if (mind[x][y ^ BIN(*i)] == -1) {
                    mind[x][y ^ BIN(*i)] = mind[x][y] + 1;
                    pre[x][y ^ BIN(*i)] = *i;
                    q[end++] = (x << MAXN) ^ (y ^ BIN(*i));
                }
            }
        }

        printf("Villa #%d\n", ++ri);
        if (mind[n - 1][BIN(n - 1)] == -1) {
            puts("The problem cannot be solved.");
        } else {
            int x = n - 1, y = BIN(n - 1);
            vector<int> ans(mind[x][y]);
            printf("The problem can be solved in %d steps:\n", mind[n - 1][BIN(n - 1)]);
            for (vector<int>::reverse_iterator i = ans.rbegin(); i != ans.rend(); ++i) {
                if (pre[x][y] >= 0) {
                    *i = pre[x][y];
                    y ^= BIN(*i);
                } else {
                    *i = -1 - x;
                    x = -1 - pre[x][y];
                }
            }
            for (vector<int>::const_iterator i = ans.begin(); i != ans.end(); ++i) {
                if (*i >= 0) {
                    printf("- Switch %s light in room %d.\n", (y & BIN(*i)) == 0 ? "on" : "off", *i + 1);
                    y ^= BIN(*i);
                } else {
                    printf("- Move to room %d.\n", -*i);
                    x = -1 - *i;
                }
            }
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//290   2010-06-27 06:03:25     Accepted    1024    C++     0   180     anotherpeg  Source

// 2012-09-30 23:39:42 | Accepted | 1301 | C++ | 0 | 180 | watashi | Source
