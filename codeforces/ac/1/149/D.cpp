#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 707;
const long long MOD = 1000000007;

int m[MAXN];
char s[MAXN];
long long dp[MAXN][MAXN][3][3];

long long gao(int l, int r, int s, int t) {
    long long &ret = dp[l][r][s][t];
    if (ret == -1) {
        ret = 0;
        if (l > r) {
            ret = s == 0 && t == 0 ? 1 : 0;
        } else if (m[l] == r) {
            if ((s == 0) ^ (t == 0)) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if ((s == 0 || i != s) && (t == 0 || j != t)) {
                            ret += gao(l + 1, r - 1, i, j);
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i == 0 || j == 0 || i != j) {
                        ret += gao(l, m[l], s, i) * gao(m[l] + 1, r, j, t) % MOD;
                    }
                }
            }
        }
        ret %= MOD;
    }
    return ret;
}

int main() {
    int n;
    long long ans;

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] != '(') {
            continue;
        }
        for (int j = i, k = 0; ; ++j) {
            k += s[j] == '(' ? 1 : -1;
            if (k == 0) {
                m[i] = j;
                break;
            }
        }
    }

    fill(dp[0][0][0], dp[MAXN][0][0], -1);
    ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans += gao(0, n - 1, i, j);
        }
    }
    printf("%d\n", (int)(ans % MOD));

    return 0;
}
