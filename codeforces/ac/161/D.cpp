#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 50505;
const int MAXM = 505;

int n, m;
vector<int> e[MAXN];
int dp[MAXN][MAXM];
long long ans;

void gao(int v, int p) {
    dp[v][0] = 1;
    fill(dp[v] + 1, dp[v] + m + 1, 0);
    for (int w: e[v]) {
        if (w != p) {
            gao(w, v);
            for (int i = 1; i <= m; ++i) {
                ans += (long long)dp[v][i - 1] * dp[w][m - i];
            }
            for (int i = 1; i <= m; ++i) {
                dp[v][i] += dp[w][i - 1];
            }
        }
    }
}

int main() {
    int a, b;

    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    gao(1, -1);
    cout << ans << endl;

    return 0;
}

