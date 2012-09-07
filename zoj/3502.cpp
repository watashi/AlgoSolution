#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const int MAXN = 12;

double p[MAXN][MAXN];
double dp[1 << MAXN];
string pre[1 << MAXN];

int main() {
    int re, n;
    double q;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%lf", &p[i][j]);
            }
        }
        dp[0] = 0;
        pre[0] = "";
        for (int k = 1; k < (1 << n); ++k) {
            dp[k] = -1;
            for (int i = 0; i < n; ++i) {
                if (k & (1 << i)) {
                    q = 0;
                    for (int j = 0; j < n; ++j) {
                        if (k & (1 << j)) {
                            q = max(q, p[j][i]);
                        }
                    }
                    q = dp[k ^ (1 << i)] + q / 100;
                    if ((q > dp[k] + EPS) || (q > dp[k] - EPS && pre[k ^ (1 << i)] < pre[k])) {
                        dp[k] = q;
                        pre[k] = pre[k ^ (1 << i)];
                        pre[k] += ('A' + i);
                    }
                }
            }
        }
        printf("%.2f\n%s\n", dp[(1 << n) - 1], pre[(1 << n) - 1].c_str());
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//740   2011-04-27 03:24:50     Accepted    C   C++     40  228     watashi@ArcOfDream  Source

// 2012-09-07 16:02:42 | Accepted | 3502 | C++ | 40 | 228 | watashi | Source
