#include <cstdio>
#include <cstring>
using namespace std;

char a[101][33], b[101][33];
int na, nb, dp[101][101];
int pre[101][101];

void printit(int m, int n)
{
    if(pre[m][n] == 0) {
        --m;
        --n;
        if(dp[m][n] != 0) {
            printit(m, n);
            putchar(' ');
        }
        printf("%s", b[n]);
    } else if(pre[m][n] == 1) {
        printit(m - 1, n);
    } else {
        printit(m, n - 1);
    }
}

int main(void)
{
    while(scanf("%s", a[0]) != EOF) {
        na = 0;
        while(scanf("%s", a[++na]) != EOF && strcmp(a[na], "#") != 0);
        nb = -1;
        while(scanf("%s", b[++nb]) != EOF && strcmp(b[nb], "#") != 0);
        for (int i = 0; i <= na; i++) {
            dp[i][0] = 0;
            pre[i][0] = -1;
        }
        for (int j = 0; j <= nb; j++) {
            dp[0][j] = 0;
            pre[0][j] = -1;
        }
        for (int i = 1; i <= na; i++)
            for (int j = 1; j <= nb; j++) {
                if(strcmp(a[i - 1], b[j - 1]) == 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    pre[i][j] = 0;
                } else if(dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    pre[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    pre[i][j] = 2;
                }
            }
        if(dp[na][nb] != 0) printit(na, nb);
        putchar('\n');
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2749164 2008-02-12 15:10:36 Accepted 1939 C++ 00:00.00 524K ¤ï¤¿¤·

// 2012-09-07 01:07:21 | Accepted | 1939 | C++ | 0 | 264 | watashi | Source
