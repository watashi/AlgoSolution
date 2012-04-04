#include <string>
#include <iostream>

using namespace std;

const int MAXN = 5050;
const long long MOD = 1000000007;

long long dp[MAXN][MAXN];
string s, t;

int main() {
    int n, m;
    long long ans = 0;

    cin >> s >> t;
    n = s.length();
    m = t.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                ++dp[i][j];
                if (i > 0 && j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= MOD;
        }
        ans += dp[i][m - 1];
    }
    cout << ans % MOD << endl;

    return 0;
}

