#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000000007;

long long c[MAXN][MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

long long choose(int n, int m) {
    return 0 <= m && m <= n ? c[n][m] : 0;
}

int main() {
    int n, m, k;

    init();
    scanf("%d%d%d", &n, &m, &k);
    k *= 2;
    printf("%d\n", (int)(choose(n - 1, k) * choose(m - 1, k) % MOD));

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1152107 	Feb 6, 2012 6:16:52 AM 	watashi 	128C - Games with Rectangle 	GNU C++ 	Accepted 	50 ms 	9600 KB
