#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <numeric>

using namespace std;

long long p[10][100];
long long s[10][100];

int main() {
    int a, b;
    long long ans;

    p[0][0] = 1;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 90; ++j) {
            for (int k = 1; k <= 6; ++k) {
                p[i][j + k] += p[i - 1][j];
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        partial_sum(p[i], p[i] + 90, s[i] + 1);
    }

    while (scanf("%d%d", &a, &b) != EOF) {
        ans = 0;
        if (a > 1) {
            for (int i = 0; i < 90; ++i) {
                ans += p[a][i] * s[b][i];
            }
        }
        printf("%.40lf\n", (double)ans / s[a][90] / s[b][90]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//703   2011-02-08 17:46:00     Accepted    B   C++     0   196     watashi@ArcOfDream  Source

// 2012-09-07 15:59:08 | Accepted | 3468 | C++ | 0 | 196 | watashi | Source
