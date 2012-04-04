#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const long long INF = 1234567890123456789LL;

long long add(long long lhs, long long rhs) {
    return min(INF, lhs + rhs);
}

long long gao(int n, const char s[MAXN]) {
    long long dp[MAXN][MAXN];

    fill(dp[0], dp[n + 1], 0);
    dp[0][0] = 1LL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] > 0) {
                if (s[i] != ')') {
                    dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
                }
                if (s[i] != '(' && j > 0) {
                    dp[i + 1][j - 1] = add(dp[i + 1][j - 1], dp[i][j]);
                }
            }
        }
    }
    return dp[n][0];
}

int main() {
    int n, m, t;
    long long d, y;
    char s[MAXN];
    pair<int, int> p[MAXN];

    cin >> n >> m >> d;
    for (int i = 0; i < n + m - 1; ++i) {
        p[i].first = n * m;
        p[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t;
            p[i + j].first = min(p[i + j].first, t);
            p[i + j].second = i + j;
        }
    }
    t = n + m - 1;
    sort(p, p + t);

    fill(s, s + t, '?');
    for (int i = 0; i < n + m - 1; ++i) {
        s[p[i].second] = '(';
        y = gao(t, s);
        if (d > y) {
            d -= y;
            s[p[i].second] = ')';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << s[i + j];
        }
        cout << endl;
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1155343 	Feb 7, 2012 1:22:49 PM 	watashi 	123C - Brackets 	GNU C++0x 	Accepted 	50 ms 	1700 KB
