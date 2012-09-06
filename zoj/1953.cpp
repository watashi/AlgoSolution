//LCS

#include <cstdio>
#include <cstring>

char sa[108], sb[108];
int la, lb;
int dp[101][101][2];

void printit(int i, int j)
{
    switch(dp[i][j][1]) {
        case 0:
            printit(--i, --j);
            putchar(sa[i]);
            break;
        case 1:
            printit(--i, j);
            putchar(sa[i]);
            break;
        case 2:
            printit(i, --j);
            putchar(sb[j]);
            break;
    }
}

int main(void)
{
    int i, j;

    while(scanf("%s%s", sa, sb) != EOF) {
        la = strlen(sa);
        lb = strlen(sb);
        dp[0][0][0] = 0;
        dp[0][0][1] = -1;
        for (i = 1; i <= la; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = 1;
        }
        for (j = 1; j <= lb; j++) {
            dp[0][j][0] = 0;
            dp[0][j][1] = 2;
        }
        for (i = 1; i <= la; i++)
            for (j = 1; j <= lb; j++) {
                if(sa[i - 1] == sb[j - 1]) {
                    dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
                    dp[i][j][1] = 0;
                }
                else if(dp[i - 1][j][0] >= dp[i][j - 1][0]) {
                    dp[i][j][0] = dp[i - 1][j][0];
                    dp[i][j][1] = 1;
                }
                else {
                    dp[i][j][0] = dp[i][j - 1][0];
                    dp[i][j][1] = 2;
                }
            }
        printit(la, lb);
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2796389 2008-03-22 12:58:23 Accepted 1953 C++ 00:00.00 508K ¤ï¤¿¤·

// 2012-09-07 01:08:18 | Accepted | 1953 | C++ | 0 | 260 | watashi | Source
