#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 4040;
const long long INF = 0x123456789ABCDEFLL;

long long a[MAXN];
long long s[MAXN];
long long dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int main() {
    int n, m;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    partial_sum(a, a + n, s);
    fill(dp[0], dp[n], INF);
    for (int i = 0; i < n; ++i) {
        dp[i][0] = -INF;
        dp[i][1] = s[i];
        for (int j = 0; j < i; ++j) {
            int k = lower_bound(dp[j], dp[j + 1], s[i] - s[j]) - dp[j];
            if (k > 1 && dp[j][k - 1] < s[i] - s[j] && dp[i][k] > s[i] - s[j]) {
                dp[i][k] = s[i] - s[j];
                pre[i][k] = j;
            }
        }
        /*
        for (int j = 0; j < n; ++j) {
            printf("[%d][%d] = %lld\n", i, j, dp[i][j]);
        }
        */
        for (int j = n; j >= 0; --j) {
            if (dp[i][j] > dp[i][j + 1]) {
                dp[i][j] = dp[i][j + 1];
                pre[i][j] = pre[i][j + 1];
            }
        }
    }

    m = 1;
    while (dp[n - 1][m + 1] < INF) {
        ++m;
    }
    printf("%d\n", m);
    vector<int> v;
    for (int i = n - 1, j = m; j > 1; i = pre[i][j], --j) {
        v.push_back(pre[i][j] + 1);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i > 0) {
            putchar(' ');
        }
        printf("%d", v[i]);
    }
    puts("");

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485977 	watashi 	2430 	: Accepted 	C++ 	00:25 sec 	190072 KB 	1536 Bytes 	Sun Sep 16 02:05:35

