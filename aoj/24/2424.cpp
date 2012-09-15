#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

int dp[MAXN];

int main() {
    int re, n;

    for (int i = 10; i < MAXN; ++i) {
        int k = 0;
        for (int j = 10; j <= i; j *= 10) {
            k = max(k, (i / j) * (i % j));
        }
        dp[i] = dp[k] + 1;
    }
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485970 	watashi 	2424 	: Accepted 	C++ 	00:02 sec 	5124 KB 	461 Bytes 	Sun Sep 16 02:00:56

