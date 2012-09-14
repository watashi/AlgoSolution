// If there are more than one player getting the most points, the one with the smallest string number wins.
// 应该倒过来dp!!!

#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

int pt[1000];
int dp[10000][10][10];
int pr[10000][10][10];

int main(void)
{
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        fill(pt, pt + 1000, 0);
        while(m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            pt[a] = b;
        }
        fill(dp[0][0], dp[0][10], 0);
        for (int l = 1; l + 2 <= n; l++) {
            fill(dp[l][0], dp[l][10], numeric_limits<int>::min());
            int c = 0;
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    for (int k = 0; k < 10; k++) {
                        int tmp = dp[l - 1][j][k] + pt[c];
                        if(tmp > dp[l][i][j]) {
                            dp[l][i][j] = tmp;
                            pr[l][i][j] = k;
                        }
                        c++;
                    }
        }
        int x = 0, y = 0, z = n - 2;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if(dp[z][i][j] > dp[z][x][y]) {
                    x = i;
                    y = j;
                }
        putchar('0' + x);
        putchar('0' + y);
        for (int k = z; k > 0; k--) {
            int t = pr[k][x][y];
            x = y;
            y = t;
            putchar('0' + t);
        }
        putchar('\n');
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2747334 2008-02-09 22:39:50 Accepted 1206 C++ 00:00.36 8252K わたし

// 2012-09-07 00:41:50 | Accepted | 1206 | C++ | 170 | 7996 | watashi | Source
