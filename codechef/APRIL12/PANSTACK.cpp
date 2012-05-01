#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000000007LL;

long long dp[MAXN][MAXN];

inline void add(long long& a, long long b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void init() {
    dp[1][1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        copy(dp[i - 1], dp[i - 1] + i, dp[i] + 1);
        for (int j = 1; j < i; ++j) {
            add(dp[i][j], dp[i - 1][j] * j % MOD);
        }
    }
}

int main() {
    int re, n;

    init();
    cin >> re;
    for (int ri = 1; ri <= re; ++ri) {
        cin >> n;
        cout << accumulate(dp[n], dp[n] + MAXN, 0LL) % MOD << endl;
    }

    return 0;
}

