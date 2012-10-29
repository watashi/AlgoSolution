#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2012;
const long long MOD = 1000003;

char buf[MAXN];
long long dp[MAXN][MAXN];

long long gao(int begin, int end) {
        long long &ret = dp[begin][end];
       
        if (ret == -1) {
                ret = 0;
                if (begin < end) {
                        if (buf[begin] == '+' || buf[begin] == '-') {
                                ret = (ret + gao(begin + 1, end)) % MOD;
                        }
                        bool num = true;
                        for (int i = begin; i < end; ++i) {
                                if (!isdigit(buf[i])) {
                                        num = false;
                                        ret = (ret + gao(begin, i) * gao(i + 1, end)) % MOD;
                                }
                        }
                        if (num) {
                                ret = (ret + 1) % MOD;
                        }
                }
        }

        return ret;
}

int main() {
        int n;

        scanf("%s", buf);
        n = strlen(buf);
        fill(dp[0], dp[n + 1], -1);
        printf("%d\n", (int)gao(0, n));

        return 0;
}
