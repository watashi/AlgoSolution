#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1000000007;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
long long dp[MAXN];
vector<pair<int, int> > v;

int main() {
    int re, n, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            d[i] = INF;
            dp[i] = 0;
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d%d%d", &a[j * 2], &b[j * 2], &c[j * 2]);
            --a[j * 2];
            --b[j * 2];
            a[j * 2 + 1] = b[j * 2];
            b[j * 2 + 1] = a[j * 2];
            c[j * 2 + 1] = c[j * 2];
        }

        d[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m + m; ++j) {
                if (d[b[j]] > d[a[j]] + c[j]) {
                    d[b[j]] = d[a[j]] + c[j];
                }
            }
        }

        v.clear();
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(d[i], i));
        }
        sort(v.begin(), v.end());

        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int s = v[i].second;
            // printf("[%d] = %d\n", s, d[s]);
            for (int j = 0; j < m + m; ++j) {
                if (a[j] == s && d[b[j]] == d[a[j]] + c[j]) {
                    dp[b[j]] += dp[a[j]];
                }
            }
        }
        printf("%lld\n", dp[n - 1]);
    }

    return 0;
}

