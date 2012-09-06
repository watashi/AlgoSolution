/*
-- HH HT TT
HH 1  2  3
HT -1 0  1
TT -3 0  1
*/
#include <stdio.h>
int main()
{
    int i, j;
    double win, lose, tie, sum, dp[21][203];

    for (j = 0; j < 203; j++)
        dp[0][j] = 0;
    dp[0][100] = 1;
    printf("Round   A wins    B wins    Tie\n");
    for(i = 1; i <= 20; i++){
        win = lose = tie = sum = 0;
        for(j = 0; j < 3; j++)
            dp[i][j] = 0;
        for(j = 3; j < 200; j++){
            dp[i][j] = dp[i - 1][j - 3] + 2 * dp[i - 1][j - 2] + 4 * dp[i - 1][j - 1] +
                6 * dp[i - 1][j] + 2 * dp[i - 1][j + 1] + dp[i - 1][j + 3];
            sum += dp[i][j];
            if(j < 100) win += dp[i][j];
            else if(j == 100) tie = dp[i][j];
            else lose += dp[i][j];
        }
        for(j = 200; j < 203; j++)
            dp[i][j] = 0;
        printf("%5d %9.4lf%%%9.4lf%%%9.4lf%%\n", i, 100.0 * lose / sum, 100.0 * win / sum, 100.0 * tie / sum);
    }

    return 0;   /* NZEC */
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2708771    2007-12-22 00:39:45     Accepted    1349    C   00:00.00    416K    ¤ï¤¿¤· */

// 2012-09-07 02:59:54 | Accepted | 1349 | C | 0 | 156 | watashi | Source
