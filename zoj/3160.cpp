#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

bool _8g[333][333];
bool _dp[333][333];
int dp[333];

int main(void)
{
    int n, m, l;

    while (scanf("%d%d", &n, &m) != EOF) {
        vector<pair<int, int> > tmp(m);
        vector<int> cur(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &tmp[i].first, &tmp[i].second);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &l);
            cur[l] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                _8g[i][j] = _dp[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            _8g[cur[tmp[i].first]][cur[tmp[i].second]] = _8g[cur[tmp[i].second]][cur[tmp[i].first]] = true;
        }
        tmp.clear();
        cur.clear();

        for (int i = 1; i < n; i++) {
            _dp[i - 1][i] = _8g[i - 1][i];
        }
        for (int k = 3; k < n; k += 2) {
            for (int i = 0; i + k < n; i++) {
                if (_8g[i][i + k] && _dp[i + 1][i + k - 1]) {
                    _dp[i][i + k] = true;
                    continue;
                }
                for (int j = 1; j != k; j += 2) {
                    if (_dp[i][i + j] && _dp[i + j + 1][i + k]) {
                        _dp[i][i + k] = true;
                        break;
                    }
                }
            }
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 2; j >= 0; j -= 2) {
                if (_dp[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        printf("%d\n", n - dp[n]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801090   2009-03-23 21:02:28     Accepted    3160    C++     20  396     watashi@Zodiac

// 2012-09-07 02:04:41 | Accepted | 3160 | C++ | 10 | 396 | watashi | Source
