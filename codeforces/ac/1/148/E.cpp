#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = 10086;

int dp[MAXM];

int main() {
    int n, m, c, s, a[MAXN], b[MAXN];

    scanf("%d%d", &n, &m);
    fill(dp, dp + m + 1, 0);
    s = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c);
        s += c;
        a[0] = 0;
        for (int j = 0; j < c; ++j) {
            scanf("%d", &a[j + 1]);
            a[j + 1] += a[j];
        }
        fill(b, b + c + 1, 0);
        b[c] = a[c];
        for (int j = 0; j < c; ++j) {
            for (int k = j + 1; k <= c; ++k) {
                b[c - (k - j)] = max(b[c - (k - j)], a[c] - (a[k] - a[j]));
            }
        }
        for (int j = min(s, m); j >= 0; --j) {
            for (int k = min(j, c); k > 0; --k) {
                dp[j] = max(dp[j], dp[j - k] + b[k]);
            }
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1144451 	Feb 3, 2012 12:06:17 AM 	watashi 	148E - Porcelain 	GNU C++0x 	Accepted 	110 ms 	1400 KB

