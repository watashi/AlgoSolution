#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5000;
const long long INF = 1000000007LL * 1000000007LL;

long long w[MAXN], ws[MAXN];
int pre[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main() {
    int n;

    scanf("%d", &n);
    ws[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &w[i]);
        ws[i + 1] = ws[i] + w[i];
        dp[i][i + 1] = 0;
        pre[i][i + 1] = i;
    }
    for (int m = 2; m <= n; ++m) {
        for (int i = 0; i + m <= n; ++i) {
            int j = i + m;
            dp[i][j] = INF;
            for (int k = max(i + 1, pre[i][j - 1]); k <= pre[i + 1][j]; ++k) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    pre[i][j] = k;
                }
            }
            dp[i][j] += ws[j] - ws[i];
        }
    }
    printf("%lld\n", dp[0][n]);

    return 0;
}

/*
Run# 	提出者 	問題 	結果 	言語 	時間 	メモリ 	コード長 	提出日時
#485487 	watashi 	2415 	: Accepted 	C++ 	00:15 sec 	238444 KB 	922 Bytes 	Sat Sep 15 17:19:55
*/
